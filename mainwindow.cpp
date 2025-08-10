#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    wireUi();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::wireUi() {
    // вкладка Посты
    connect(ui->btnCollectPosts, &QPushButton::clicked, this, &MainWindow::onCollectPosts);
    connect(ui->btnSavePosts,    &QPushButton::clicked, this, &MainWindow::onSavePosts);

    // вкладка Контакты
    connect(ui->btnPickPostsFile, &QPushButton::clicked, this, &MainWindow::onPickPostsFile);
    connect(ui->btnRunContacts,   &QPushButton::clicked, this, &MainWindow::onRunCollectContacts);
    connect(ui->btnSaveContacts,  &QPushButton::clicked, this, &MainWindow::onSaveContacts);

    // вкладка Рассылка/Инвайт
    connect(ui->btnPickUsersFile, &QPushButton::clicked, this, &MainWindow::onPickUsersFile);
    connect(ui->btnPickLogFile,   &QPushButton::clicked, this, &MainWindow::onPickLogFile);
    connect(ui->btnStart,         &QPushButton::clicked, this, &MainWindow::onStartDispatch);

    // значения по умолчанию
    ui->comboMode->addItems({"invite", "message"});
    ui->spinPerHour->setRange(0, 10000);  ui->spinPerHour->setValue(25);
    ui->spinPerDay->setRange(0, 100000);  ui->spinPerDay->setValue(100);
    ui->spinMinDelay->setRange(0, 600);   ui->spinMinDelay->setValue(3);
    ui->spinMaxDelay->setRange(0, 1200);  ui->spinMaxDelay->setValue(8);
    ui->spinMaxErrors->setRange(0, 1000); ui->spinMaxErrors->setValue(20);
    ui->checkSkipProcessed->setChecked(true);

    // disable actions that require data
    ui->btnSavePosts->setEnabled(false);
    ui->btnRunContacts->setEnabled(false);
    ui->btnSaveContacts->setEnabled(false);
}

// ── Посты (заглушки) ───────────────────────────────────────────
void MainWindow::onCollectPosts() {
    const auto url = ui->lineChannel->text().trimmed();
    if (url.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите https://t.me/<username>");
        return;
    }
    ui->btnCollectPosts->setEnabled(false);
    ui->btnSavePosts->setEnabled(false);
    ui->labelPostsStatus->setText("Сбор…");
    ui->progressPosts->setValue(0);

    m_postsWorker = new CollectPostsWorker(url, this);
    connect(m_postsWorker, &CollectPostsWorker::progress, this, [=](int d, int t){
        ui->progressPosts->setMaximum(t);
        ui->progressPosts->setValue(d);
        ui->labelPostsStatus->setText(QString("%1 / %2").arg(d).arg(t));
    });
    connect(m_postsWorker, &CollectPostsWorker::finished, this, [=]{
        m_posts = m_postsWorker->posts();
        ui->labelPostsStatus->setText(QString("Готово: %1").arg(m_posts.size()));
        ui->btnSavePosts->setEnabled(!m_posts.isEmpty());
        m_postsWorker->deleteLater();
        m_postsWorker = nullptr;
        ui->btnCollectPosts->setEnabled(true);
    });
    connect(m_postsWorker, &CollectPostsWorker::error, this, [=](const QString &msg){
        QMessageBox::critical(this, "Ошибка", msg);
        m_postsWorker->deleteLater();
        m_postsWorker = nullptr;
        ui->btnCollectPosts->setEnabled(true);
    });
    m_postsWorker->start();
}

void MainWindow::onSavePosts() {
    if (m_posts.isEmpty()) {
        QMessageBox::warning(this, "Пусто", "Нет данных для сохранения");
        return;
    }
    QString fn = QFileDialog::getSaveFileName(this, "Сохранить ссылки", "", "CSV (*.csv)");
    if (fn.isEmpty()) return;
    if (!fn.endsWith(".csv", Qt::CaseInsensitive)) fn += ".csv";
    QFile f(fn);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", f.errorString());
        return;
    }
    QTextStream out(&f);
    for (const auto &p : m_posts) out << p << "\n";
    QMessageBox::information(this, "Готово", "Ссылки сохранены");
}

// ── Контакты (заглушки) ───────────────────────────────────────
void MainWindow::onPickPostsFile() {
    QString fn = QFileDialog::getOpenFileName(this, "Открыть список постов", "", "CSV (*.csv)");
    if (fn.isEmpty()) return;
    ui->linePostsFile->setText(fn);
    m_posts.clear();
    QFile f(fn);
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&f);
        while (!in.atEnd()) m_posts << in.readLine().trimmed();
    }
    ui->labelContactsStatus->setText(QString("Постов: %1").arg(m_posts.size()));
    ui->btnRunContacts->setEnabled(!m_posts.isEmpty());
    ui->btnSaveContacts->setEnabled(false);
}

void MainWindow::onRunCollectContacts() {
    if (m_posts.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Загрузите список постов");
        return;
    }
    ui->btnRunContacts->setEnabled(false);
    ui->btnSaveContacts->setEnabled(false);
    ui->labelContactsStatus->setText("Сбор…");
    ui->progressContacts->setValue(0);

    m_contactsWorker = new CollectContactsWorker(m_posts, this);
    connect(m_contactsWorker, &CollectContactsWorker::progress, this, [=](int d, int t){
        ui->progressContacts->setMaximum(t);
        ui->progressContacts->setValue(d);
    });
    connect(m_contactsWorker, &CollectContactsWorker::finished, this, [=]{
        m_contacts = m_contactsWorker->data();
        ui->labelContactsStatus->setText(QString("Найдено: %1").arg(m_contacts.size()));
        ui->btnSaveContacts->setEnabled(!m_contacts.isEmpty());
        ui->btnRunContacts->setEnabled(true);
        m_contactsWorker->deleteLater();
        m_contactsWorker = nullptr;
    });
    connect(m_contactsWorker, &CollectContactsWorker::error, this, [=](const QString &msg){
        QMessageBox::critical(this, "Ошибка", msg);
        ui->btnRunContacts->setEnabled(true);
        m_contactsWorker->deleteLater();
        m_contactsWorker = nullptr;
    });
    m_contactsWorker->start();
}

void MainWindow::onSaveContacts() {
    if (m_contacts.isEmpty()) {
        QMessageBox::warning(this, "Пусто", "Нет данных");
        return;
    }
    QString fn = QFileDialog::getSaveFileName(this, "Сохранить контакты", "", "CSV (*.csv)");
    if (fn.isEmpty()) return;
    if (!fn.endsWith(".csv", Qt::CaseInsensitive)) fn += ".csv";
    QFile f(fn);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", f.errorString());
        return;
    }
    QTextStream out(&f);
    QStringList headers = {"user_id","username","first_name","last_name","t.me_link"};
    out << headers.join(',') << "\n";
    for (const auto &var : m_contacts) {
        const auto map = var.toMap();
        QStringList row;
        for (const auto &h : headers) row << map.value(h).toString();
        out << row.join(',') << "\n";
    }
    QMessageBox::information(this, "Готово", "Контакты сохранены");
}

// ── Рассылка/Инвайт (заглушки) ────────────────────────────────
void MainWindow::onPickUsersFile() {
    QString fn = QFileDialog::getOpenFileName(this, "Открыть пользователей", "", "Excel/CSV (*.xlsx *.csv)");
    if (fn.isEmpty()) return;
    ui->lineUsersFile->setText(fn);
}

void MainWindow::onPickLogFile() {
    QString fn = QFileDialog::getSaveFileName(this, "Выбрать/создать лог", "", "CSV (*.csv)");
    if (fn.isEmpty()) return;
    if (!fn.endsWith(".csv", Qt::CaseInsensitive)) fn += ".csv";
    ui->lineLogFile->setText(fn);
}

void MainWindow::onStartDispatch() {
    if (ui->lineUsersFile->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите файл пользователей");
        return;
    }
    if (ui->comboMode->currentText() == "invite" && ui->lineGroup->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Укажите @имя_группы для инвайта");
        return;
    }
    if (ui->comboMode->currentText() == "message" && ui->textMessage->toPlainText().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите текст сообщения для рассылки");
        return;
    }
    ui->btnStart->setEnabled(false);
    ui->progressDispatch->setValue(0);
    ui->textLog->clear();

    DispatchWorker::Mode mode = ui->comboMode->currentText() == "invite" ? DispatchWorker::Invite : DispatchWorker::Message;
    m_dispatchWorker = new DispatchWorker(mode,
                                         ui->lineUsersFile->text(),
                                         ui->lineGroup->text(),
                                         ui->textMessage->toPlainText(),
                                         this);
    connect(m_dispatchWorker, &DispatchWorker::progress, this, [=](int d, int t){
        ui->progressDispatch->setMaximum(t);
        ui->progressDispatch->setValue(d);
    });
    connect(m_dispatchWorker, &DispatchWorker::log, this, [=](const QString &txt){
        ui->textLog->appendPlainText(txt);
    });
    connect(m_dispatchWorker, &DispatchWorker::finished, this, [=]{
        ui->btnStart->setEnabled(true);
        m_dispatchWorker->deleteLater();
        m_dispatchWorker = nullptr;
        ui->textLog->appendPlainText("Готово");
    });
    m_dispatchWorker->start();
}

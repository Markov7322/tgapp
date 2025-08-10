#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>

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
}

// ── Посты (заглушки) ───────────────────────────────────────────
void MainWindow::onCollectPosts() {
    const auto url = ui->lineChannel->text().trimmed();
    if (url.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите https://t.me/<username>");
        return;
    }
    ui->labelPostsStatus->setText("Собираем посты… (демо)");
    ui->progressPosts->setMaximum(100);
    ui->progressPosts->setValue(100);
    // TODO: здесь будет вызов Telegram-логики (TDLib)
    QMessageBox::information(this, "Демо", "Каркас готов. Telegram подключим на следующем шаге.");
}

void MainWindow::onSavePosts() {
    QString fn = QFileDialog::getSaveFileName(this, "Сохранить ссылки", "", "CSV (*.csv);;Excel (*.xlsx)");
    if (fn.isEmpty()) return;
    QMessageBox::information(this, "Демо", "Сохранение реализуем после подключения данных.");
}

// ── Контакты (заглушки) ───────────────────────────────────────
void MainWindow::onPickPostsFile() {
    QString fn = QFileDialog::getOpenFileName(this, "Открыть список постов", "", "Excel/CSV (*.xlsx *.csv)");
    if (fn.isEmpty()) return;
    ui->linePostsFile->setText(fn);
    ui->labelContactsStatus->setText("Файл загружен");
}

void MainWindow::onRunCollectContacts() {
    if (ui->linePostsFile->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите файл постов");
        return;
    }
    ui->labelContactsStatus->setText("Сбор контактов… (демо)");
    ui->progressContacts->setMaximum(100);
    ui->progressContacts->setValue(100);
}

void MainWindow::onSaveContacts() {
    QString fn = QFileDialog::getSaveFileName(this, "Сохранить контакты", "", "CSV (*.csv);;Excel (*.xlsx)");
    if (fn.isEmpty()) return;
    QMessageBox::information(this, "Демо", "Сохранение реализуем после подключения данных.");
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
    ui->progressDispatch->setMaximum(100);
    ui->progressDispatch->setValue(100);
    ui->textLog->appendPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "  Демо запуск OK");
}

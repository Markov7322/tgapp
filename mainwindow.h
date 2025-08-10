#pragma once
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Посты
    void onCollectPosts();
    void onSavePosts();

    // Контакты
    void onPickPostsFile();
    void onRunCollectContacts();
    void onSaveContacts();

    // Рассылка/Инвайт
    void onPickUsersFile();
    void onPickLogFile();
    void onStartDispatch();

private:
    Ui::MainWindow *ui;
    void wireUi();
};

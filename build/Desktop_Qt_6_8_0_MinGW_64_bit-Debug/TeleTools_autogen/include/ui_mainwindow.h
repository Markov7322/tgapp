/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabPosts;
    QVBoxLayout *verticalLayout_1;
    QFormLayout *formLayout_1;
    QLabel *label_1;
    QLineEdit *lineChannel;
    QLabel *label_2;
    QLabel *labelPostsStatus;
    QHBoxLayout *hbox1;
    QPushButton *btnCollectPosts;
    QPushButton *btnSavePosts;
    QSpacerItem *sp1;
    QProgressBar *progressPosts;
    QWidget *tabContacts;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QHBoxLayout *hbox2;
    QLineEdit *linePostsFile;
    QPushButton *btnPickPostsFile;
    QLabel *label_4;
    QLabel *labelContactsStatus;
    QHBoxLayout *hbox3;
    QPushButton *btnRunContacts;
    QPushButton *btnSaveContacts;
    QSpacerItem *sp2;
    QProgressBar *progressContacts;
    QWidget *tabDispatch;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QComboBox *comboMode;
    QLabel *label_6;
    QLineEdit *lineGroup;
    QLabel *label_7;
    QPlainTextEdit *textMessage;
    QLabel *label_8;
    QHBoxLayout *hbox4;
    QLineEdit *lineUsersFile;
    QPushButton *btnPickUsersFile;
    QLabel *label_9;
    QSpinBox *spinPerHour;
    QLabel *label_10;
    QSpinBox *spinPerDay;
    QLabel *label_11;
    QSpinBox *spinMinDelay;
    QLabel *label_12;
    QSpinBox *spinMaxDelay;
    QLabel *label_13;
    QSpinBox *spinMaxErrors;
    QLabel *label_14;
    QCheckBox *checkSkipProcessed;
    QLabel *label_15;
    QHBoxLayout *hbox5;
    QLineEdit *lineLogFile;
    QPushButton *btnPickLogFile;
    QProgressBar *progressDispatch;
    QPlainTextEdit *textLog;
    QPushButton *btnStart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabPosts = new QWidget();
        tabPosts->setObjectName("tabPosts");
        verticalLayout_1 = new QVBoxLayout(tabPosts);
        verticalLayout_1->setObjectName("verticalLayout_1");
        formLayout_1 = new QFormLayout();
        formLayout_1->setObjectName("formLayout_1");
        label_1 = new QLabel(tabPosts);
        label_1->setObjectName("label_1");

        formLayout_1->setWidget(0, QFormLayout::LabelRole, label_1);

        lineChannel = new QLineEdit(tabPosts);
        lineChannel->setObjectName("lineChannel");

        formLayout_1->setWidget(0, QFormLayout::FieldRole, lineChannel);

        label_2 = new QLabel(tabPosts);
        label_2->setObjectName("label_2");

        formLayout_1->setWidget(1, QFormLayout::LabelRole, label_2);

        labelPostsStatus = new QLabel(tabPosts);
        labelPostsStatus->setObjectName("labelPostsStatus");

        formLayout_1->setWidget(1, QFormLayout::FieldRole, labelPostsStatus);


        verticalLayout_1->addLayout(formLayout_1);

        hbox1 = new QHBoxLayout();
        hbox1->setObjectName("hbox1");
        btnCollectPosts = new QPushButton(tabPosts);
        btnCollectPosts->setObjectName("btnCollectPosts");

        hbox1->addWidget(btnCollectPosts);

        btnSavePosts = new QPushButton(tabPosts);
        btnSavePosts->setObjectName("btnSavePosts");

        hbox1->addWidget(btnSavePosts);

        sp1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hbox1->addItem(sp1);


        verticalLayout_1->addLayout(hbox1);

        progressPosts = new QProgressBar(tabPosts);
        progressPosts->setObjectName("progressPosts");
        progressPosts->setTextVisible(false);
        progressPosts->setValue(0);

        verticalLayout_1->addWidget(progressPosts);

        tabWidget->addTab(tabPosts, QString());
        tabContacts = new QWidget();
        tabContacts->setObjectName("tabContacts");
        verticalLayout_2 = new QVBoxLayout(tabContacts);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_3 = new QLabel(tabContacts);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        hbox2 = new QHBoxLayout();
        hbox2->setObjectName("hbox2");
        linePostsFile = new QLineEdit(tabContacts);
        linePostsFile->setObjectName("linePostsFile");
        linePostsFile->setReadOnly(true);

        hbox2->addWidget(linePostsFile);

        btnPickPostsFile = new QPushButton(tabContacts);
        btnPickPostsFile->setObjectName("btnPickPostsFile");
        btnPickPostsFile->setMaximumWidth(40);

        hbox2->addWidget(btnPickPostsFile);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, hbox2);

        label_4 = new QLabel(tabContacts);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        labelContactsStatus = new QLabel(tabContacts);
        labelContactsStatus->setObjectName("labelContactsStatus");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, labelContactsStatus);


        verticalLayout_2->addLayout(formLayout_2);

        hbox3 = new QHBoxLayout();
        hbox3->setObjectName("hbox3");
        btnRunContacts = new QPushButton(tabContacts);
        btnRunContacts->setObjectName("btnRunContacts");

        hbox3->addWidget(btnRunContacts);

        btnSaveContacts = new QPushButton(tabContacts);
        btnSaveContacts->setObjectName("btnSaveContacts");

        hbox3->addWidget(btnSaveContacts);

        sp2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hbox3->addItem(sp2);


        verticalLayout_2->addLayout(hbox3);

        progressContacts = new QProgressBar(tabContacts);
        progressContacts->setObjectName("progressContacts");
        progressContacts->setTextVisible(false);
        progressContacts->setValue(0);

        verticalLayout_2->addWidget(progressContacts);

        tabWidget->addTab(tabContacts, QString());
        tabDispatch = new QWidget();
        tabDispatch->setObjectName("tabDispatch");
        verticalLayout_3 = new QVBoxLayout(tabDispatch);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_5 = new QLabel(tabDispatch);
        label_5->setObjectName("label_5");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        comboMode = new QComboBox(tabDispatch);
        comboMode->setObjectName("comboMode");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboMode);

        label_6 = new QLabel(tabDispatch);
        label_6->setObjectName("label_6");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        lineGroup = new QLineEdit(tabDispatch);
        lineGroup->setObjectName("lineGroup");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineGroup);

        label_7 = new QLabel(tabDispatch);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_7);

        textMessage = new QPlainTextEdit(tabDispatch);
        textMessage->setObjectName("textMessage");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, textMessage);

        label_8 = new QLabel(tabDispatch);
        label_8->setObjectName("label_8");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_8);

        hbox4 = new QHBoxLayout();
        hbox4->setObjectName("hbox4");
        lineUsersFile = new QLineEdit(tabDispatch);
        lineUsersFile->setObjectName("lineUsersFile");
        lineUsersFile->setReadOnly(true);

        hbox4->addWidget(lineUsersFile);

        btnPickUsersFile = new QPushButton(tabDispatch);
        btnPickUsersFile->setObjectName("btnPickUsersFile");
        btnPickUsersFile->setMaximumWidth(40);

        hbox4->addWidget(btnPickUsersFile);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, hbox4);

        label_9 = new QLabel(tabDispatch);
        label_9->setObjectName("label_9");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_9);

        spinPerHour = new QSpinBox(tabDispatch);
        spinPerHour->setObjectName("spinPerHour");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, spinPerHour);

        label_10 = new QLabel(tabDispatch);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_10);

        spinPerDay = new QSpinBox(tabDispatch);
        spinPerDay->setObjectName("spinPerDay");

        formLayout_3->setWidget(5, QFormLayout::FieldRole, spinPerDay);

        label_11 = new QLabel(tabDispatch);
        label_11->setObjectName("label_11");

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_11);

        spinMinDelay = new QSpinBox(tabDispatch);
        spinMinDelay->setObjectName("spinMinDelay");

        formLayout_3->setWidget(6, QFormLayout::FieldRole, spinMinDelay);

        label_12 = new QLabel(tabDispatch);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_12);

        spinMaxDelay = new QSpinBox(tabDispatch);
        spinMaxDelay->setObjectName("spinMaxDelay");

        formLayout_3->setWidget(7, QFormLayout::FieldRole, spinMaxDelay);

        label_13 = new QLabel(tabDispatch);
        label_13->setObjectName("label_13");

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_13);

        spinMaxErrors = new QSpinBox(tabDispatch);
        spinMaxErrors->setObjectName("spinMaxErrors");

        formLayout_3->setWidget(8, QFormLayout::FieldRole, spinMaxErrors);

        label_14 = new QLabel(tabDispatch);
        label_14->setObjectName("label_14");

        formLayout_3->setWidget(9, QFormLayout::LabelRole, label_14);

        checkSkipProcessed = new QCheckBox(tabDispatch);
        checkSkipProcessed->setObjectName("checkSkipProcessed");

        formLayout_3->setWidget(9, QFormLayout::FieldRole, checkSkipProcessed);

        label_15 = new QLabel(tabDispatch);
        label_15->setObjectName("label_15");

        formLayout_3->setWidget(10, QFormLayout::LabelRole, label_15);

        hbox5 = new QHBoxLayout();
        hbox5->setObjectName("hbox5");
        lineLogFile = new QLineEdit(tabDispatch);
        lineLogFile->setObjectName("lineLogFile");
        lineLogFile->setReadOnly(true);

        hbox5->addWidget(lineLogFile);

        btnPickLogFile = new QPushButton(tabDispatch);
        btnPickLogFile->setObjectName("btnPickLogFile");
        btnPickLogFile->setMaximumWidth(40);

        hbox5->addWidget(btnPickLogFile);


        formLayout_3->setLayout(10, QFormLayout::FieldRole, hbox5);


        verticalLayout_3->addLayout(formLayout_3);

        progressDispatch = new QProgressBar(tabDispatch);
        progressDispatch->setObjectName("progressDispatch");
        progressDispatch->setTextVisible(false);
        progressDispatch->setValue(0);

        verticalLayout_3->addWidget(progressDispatch);

        textLog = new QPlainTextEdit(tabDispatch);
        textLog->setObjectName("textLog");

        verticalLayout_3->addWidget(textLog);

        btnStart = new QPushButton(tabDispatch);
        btnStart->setObjectName("btnStart");

        verticalLayout_3->addWidget(btnStart);

        tabWidget->addTab(tabDispatch, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TeleTools", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273:", nullptr));
        lineChannel->setPlaceholderText(QCoreApplication::translate("MainWindow", "https://t.me/username", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        labelPostsStatus->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262", nullptr));
        btnCollectPosts->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\277\320\276\321\201\321\202\321\213", nullptr));
        btnSavePosts->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214\342\200\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPosts), QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\277\320\276\321\201\321\202\320\276\320\262:", nullptr));
        btnPickPostsFile->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        labelContactsStatus->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262", nullptr));
        btnRunContacts->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\321\200\320\260\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202\321\213", nullptr));
        btnSaveContacts->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214\342\200\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabContacts), QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\260 (\320\264\320\273\321\217 invite):", nullptr));
        lineGroup->setPlaceholderText(QCoreApplication::translate("MainWindow", "@group_or_channel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 (\320\264\320\273\321\217 message):", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271:", nullptr));
        btnPickUsersFile->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\274\320\270\321\202 \320\262 \321\207\320\260\321\201:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\274\320\270\321\202 \320\262 \321\201\321\203\321\202\320\272\320\270:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \320\274\320\270\320\275, \321\201\320\265\320\272:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \320\274\320\260\320\272\321\201, \321\201\320\265\320\272:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\276\321\210\320\270\320\261\320\276\320\272:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\277\321\203\321\201\320\272\320\260\321\202\321\214 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\321\205:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263-\321\204\320\260\320\271\320\273 CSV:", nullptr));
        btnPickLogFile->setText(QCoreApplication::translate("MainWindow", "\360\237\223\201", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDispatch), QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\213\320\273\320\272\320\260 / \320\230\320\275\320\262\320\260\320\271\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *square8;
    QPushButton *square9;
    QLabel *label;
    QLabel *temp_label;
    QPushButton *square1;
    QPushButton *square3;
    QPushButton *square7;
    QPushButton *square2;
    QPushButton *square5;
    QPushButton *square4;
    QPushButton *square6;
    QLabel *label2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        square8 = new QPushButton(centralwidget);
        square8->setObjectName(QString::fromUtf8("square8"));
        square8->setGeometry(QRect(230, 130, 80, 18));
        square9 = new QPushButton(centralwidget);
        square9->setObjectName(QString::fromUtf8("square9"));
        square9->setGeometry(QRect(230, 200, 80, 18));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 300, 151, 61));
        temp_label = new QLabel(centralwidget);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        temp_label->setGeometry(QRect(460, 50, 231, 51));
        square1 = new QPushButton(centralwidget);
        square1->setObjectName(QString::fromUtf8("square1"));
        square1->setGeometry(QRect(10, 60, 80, 18));
        square1->setAutoRepeatInterval(100);
        square3 = new QPushButton(centralwidget);
        square3->setObjectName(QString::fromUtf8("square3"));
        square3->setGeometry(QRect(10, 200, 80, 18));
        square7 = new QPushButton(centralwidget);
        square7->setObjectName(QString::fromUtf8("square7"));
        square7->setGeometry(QRect(120, 200, 80, 18));
        square2 = new QPushButton(centralwidget);
        square2->setObjectName(QString::fromUtf8("square2"));
        square2->setGeometry(QRect(120, 60, 80, 18));
        square5 = new QPushButton(centralwidget);
        square5->setObjectName(QString::fromUtf8("square5"));
        square5->setGeometry(QRect(10, 130, 80, 18));
        square4 = new QPushButton(centralwidget);
        square4->setObjectName(QString::fromUtf8("square4"));
        square4->setGeometry(QRect(120, 130, 80, 18));
        square6 = new QPushButton(centralwidget);
        square6->setObjectName(QString::fromUtf8("square6"));
        square6->setGeometry(QRect(230, 60, 80, 18));
        square6->setBaseSize(QSize(10, 10));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(460, 10, 201, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        square8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QString());
        temp_label->setText(QString());
        square1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        square6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

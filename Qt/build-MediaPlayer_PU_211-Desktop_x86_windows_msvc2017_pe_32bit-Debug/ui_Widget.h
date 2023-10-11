/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelComposition;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonNext;
    QSlider *horizontalSliderVolume;
    QSlider *horizontalSliderProgress;
    QLabel *labelVolume;
    QLabel *labelPlayed;
    QLabel *labelDuration;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonMute;
    QTableView *tablePlaylist;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(676, 408);
        Widget->setMinimumSize(QSize(676, 408));
        Widget->setMaximumSize(QSize(676, 408));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ICO/ICO/sound.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        labelComposition = new QLabel(Widget);
        labelComposition->setObjectName(QString::fromUtf8("labelComposition"));
        labelComposition->setGeometry(QRect(30, 30, 511, 16));
        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(30, 70, 51, 21));
        pushButtonPrev = new QPushButton(Widget);
        pushButtonPrev->setObjectName(QString::fromUtf8("pushButtonPrev"));
        pushButtonPrev->setGeometry(QRect(90, 70, 51, 21));
        pushButtonPlay = new QPushButton(Widget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(150, 70, 51, 21));
        pushButtonPause = new QPushButton(Widget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(210, 70, 51, 21));
        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(330, 70, 51, 21));
        horizontalSliderVolume = new QSlider(Widget);
        horizontalSliderVolume->setObjectName(QString::fromUtf8("horizontalSliderVolume"));
        horizontalSliderVolume->setGeometry(QRect(449, 70, 201, 20));
        horizontalSliderVolume->setOrientation(Qt::Horizontal);
        horizontalSliderProgress = new QSlider(Widget);
        horizontalSliderProgress->setObjectName(QString::fromUtf8("horizontalSliderProgress"));
        horizontalSliderProgress->setGeometry(QRect(30, 130, 621, 16));
        horizontalSliderProgress->setOrientation(Qt::Horizontal);
        labelVolume = new QLabel(Widget);
        labelVolume->setObjectName(QString::fromUtf8("labelVolume"));
        labelVolume->setGeometry(QRect(500, 40, 141, 20));
        labelPlayed = new QLabel(Widget);
        labelPlayed->setObjectName(QString::fromUtf8("labelPlayed"));
        labelPlayed->setGeometry(QRect(30, 110, 111, 16));
        labelDuration = new QLabel(Widget);
        labelDuration->setObjectName(QString::fromUtf8("labelDuration"));
        labelDuration->setGeometry(QRect(560, 110, 91, 16));
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(270, 70, 51, 21));
        pushButtonMute = new QPushButton(Widget);
        pushButtonMute->setObjectName(QString::fromUtf8("pushButtonMute"));
        pushButtonMute->setGeometry(QRect(390, 70, 51, 21));
        tablePlaylist = new QTableView(Widget);
        tablePlaylist->setObjectName(QString::fromUtf8("tablePlaylist"));
        tablePlaylist->setGeometry(QRect(30, 160, 621, 231));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Media Player PU_211", nullptr));
        labelComposition->setText(QCoreApplication::translate("Widget", "Composition:", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Widget", "Add", nullptr));
        pushButtonPrev->setText(QString());
        pushButtonPlay->setText(QString());
        pushButtonPause->setText(QString());
        pushButtonNext->setText(QString());
        labelVolume->setText(QCoreApplication::translate("Widget", "Volume:", nullptr));
        labelPlayed->setText(QCoreApplication::translate("Widget", "Played:", nullptr));
        labelDuration->setText(QCoreApplication::translate("Widget", "Duration:", nullptr));
        pushButtonStop->setText(QString());
        pushButtonMute->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

#include "Widget.h"
#include "ui_Widget.h"
#include <QStyle>
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	ui->pushButtonAdd->setIcon(style()->standardIcon(QStyle::SP_DriveDVDIcon));
	ui->pushButtonPrev->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui->pushButtonPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	ui->pushButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui->pushButtonNext->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

	m_player = new QMediaPlayer(this);
	m_player->setVolume(70);
	ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
	ui->horizontalSliderVolume->setValue(m_player->volume());
}

Widget::~Widget()
{
	delete ui;
}


void Widget::on_pushButtonAdd_clicked()
{
	QString file = QFileDialog::getOpenFileName(this, tr("Open file"), nullptr, tr("Audio files (*.mp3 *.flac)"));
	ui->labelComposition->setText(file);
	m_player->setMedia(QUrl::fromLocalFile(file));
}

void Widget::on_horizontalSliderVolume_valueChanged(int value)
{
	ui->labelVolume->setText(QString("Volume: ").append(QString::number(value)));
	m_player->setVolume(value);
}

void Widget::on_pushButtonPlay_clicked()
{
	m_player->play();
}

void Widget::on_pushButtonPause_clicked()
{
	m_player->pause();
}

void Widget::on_pushButtonStop_clicked()
{
	m_player->stop();
}

#include "Widget.h"
#include "ui_Widget.h"
#include <QStyle>
#include <QFileDialog>
#include <QDir>
#include <QTime>
#include <QMessageBox>
#include <QMediaContent>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	//			Buttons style
	ui->pushButtonAdd->setIcon(style()->standardIcon(QStyle::SP_DriveDVDIcon));
	ui->pushButtonPrev->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui->pushButtonPause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	ui->pushButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui->pushButtonNext->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
	ui->pushButtonMute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
	this->muted = false;
	//ui->horizontalSliderProgress->setTickPosition(QSlider::TicksBelow);

	//			Player init
	m_player = new QMediaPlayer(this);
	m_player->setVolume(70);
	ui->labelVolume->setText(QString("Volume: ").append(QString::number(m_player->volume())));
	ui->horizontalSliderVolume->setValue(m_player->volume());

	connect(m_player, &QMediaPlayer::durationChanged, this, &Widget::on_duration_changed);
	connect(m_player, &QMediaPlayer::positionChanged, this, &Widget::on_position_changed);

	/////////////////////			Playlist			/////////////////////
	m_playlist_model = new QStandardItemModel(this);
	ui->tablePlaylist->setModel(m_playlist_model);		//связываем таблицу с моделью
	m_playlist_model->setHorizontalHeaderLabels(QStringList() << tr("Audio track") << tr("File path"));	//подписываем заголовки таблицы
	ui->tablePlaylist->hideColumn(1);	//скрываем столбец с адресом файла
	ui->tablePlaylist->horizontalHeader()->setStretchLastSection(true);		//расягиваем отображаемый столбец на всю ширину окна
	ui->tablePlaylist->setEditTriggers(QAbstractItemView::NoEditTriggers);	//запрещаем редактирование ячеек таблицы

	m_playlist = new QMediaPlaylist(m_player);
	m_player->setPlaylist(m_playlist);

	connect(ui->tablePlaylist, &QTableView::doubleClicked,
			[this](const QModelIndex& index){ m_playlist->setCurrentIndex(index.row()); m_player->play(); });
	connect(m_playlist, &QMediaPlaylist::currentIndexChanged,
			[this](int index)
	{
		ui->labelComposition->setText(m_playlist_model->data(m_playlist_model->index(index, 0)).toString());
		ui->tablePlaylist->selectRow(index);
	}
			);

	/////////////////////////////////////////////////////////////////////////

	/////////////////////		   LoadPlaylist			/////////////////////
	m_playlist->load(QUrl::fromLocalFile("D:/Users/Clayman/Source/Repos/PU_211_Win/Qt/build-MediaPlayer_PU_211-Desktop_Qt_5_15_0_MSVC2015_64bit-Debug/debug/playlist.m3u"), "m3u");
	for(int i = 0; i < m_playlist->mediaCount(); i++)
	{
//		QList<QStandardItem*> item =
		QMediaContent content = m_playlist->media(i);
		QString url = content.canonicalUrl().url();
		//QMessageBox mb(QMessageBox::Icon::Information, QString("URL"), url, QMessageBox::StandardButton::Ok, this);
		//mb.show();
		QList<QStandardItem*> items;
		items.append(new QStandardItem(QDir(url).dirName()));
		items.append(new QStandardItem(url));
		m_playlist_model->appendRow(items);
	}
}

Widget::~Widget()
{
	//QMessageBox mb(QMessageBox::Icon::Information, QString("Buy"), QString("Buy"), QMessageBox::StandardButton::Ok, this);
	//mb.show();
	//m_playlist->save(QUrl::fromLocalFile("D:/Users/Clayman/Source/Repos/PU_211_Win/Qt/build-MediaPlayer_PU_211-Desktop_Qt_5_15_0_MSVC2015_64bit-Debug/debug/playlist.m3u"), "m3u");

	delete this->m_playlist_model;
	delete this->m_playlist;
	delete this->m_player;
	delete ui;
}


void Widget::on_pushButtonAdd_clicked()
{
//	QString file = QFileDialog::getOpenFileName(
//				this,
//				tr("Open file"),
//				QString("D:\\Users\\Clayman\\Music\\Sergo"),
//				tr("Audio files (*.mp3 *.flac);; mp-3 (*.mp3);; Flac (*.flac)")
//				);
//	ui->labelComposition->setText(file);
//	m_player->setMedia(QUrl::fromLocalFile(file));
//	m_player->play();

	//QStringList path = file.split('/');
	//this->setWindowTitle("Media Player PU_211 - " + path.back());

	//this->setWindowTitle("Media Player PU_211 - " + file.split('/').back());

	QStringList files = QFileDialog::getOpenFileNames(
				this,
				tr("Open files"),
				QString("D:\\Users\\Clayman\\Music\\Sergo"),
				tr("Audio files (*.mp3 *.flac);; mp-3 (*.mp3);; Flac (*.flac)")
				);
	for(QString filesPath: files)
	{
		//1) Создаем строку:
		//Каждая строка таблицы 'tablePlaylist' - это список стандартных вхождений
		QList<QStandardItem*> items;
		items.append(new QStandardItem(QDir(filesPath).dirName()));
		items.append(new QStandardItem(filesPath));
		m_playlist_model->appendRow(items);
		m_playlist->addMedia(QUrl(filesPath));
	}
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

void Widget::on_duration_changed(qint64 duration)
{
	ui->horizontalSliderProgress->setMaximum(duration);
	QTime qt_duration = QTime::fromMSecsSinceStartOfDay(duration);
	ui->labelDuration->setText(QString("Duration: ").append(qt_duration.toString("mm:ss")));
}

void Widget::on_position_changed(qint64 position)
{
	ui->horizontalSliderProgress->setValue(position);
	QTime qt_position = QTime::fromMSecsSinceStartOfDay(position);
	ui->labelPlayed->setText(QString("Played: ").append(qt_position.toString("mm:ss")));
}

void Widget::on_horizontalSliderProgress_valueChanged(qint64 position)
{
	m_player->setPosition(position);
}

void Widget::on_pushButtonMute_clicked()
{
	muted = !muted;
	m_player->setMuted(muted);
	ui->pushButtonMute->setIcon
			(style()->standardIcon(muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume));
}

void Widget::on_pushButtonNext_clicked()
{
	m_playlist->next();
}

void Widget::on_pushButtonPrev_clicked()
{
	m_playlist->previous();
}

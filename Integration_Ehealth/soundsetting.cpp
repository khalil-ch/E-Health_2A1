#include "soundsetting.h"
#include "ui_soundsetting.h"
#include <QFileDialog>
#include <QString>
#include <QMediaPlayer>
Soundsetting::Soundsetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Soundsetting)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint32 pos){
        ui->VolumeMediaDisplay->setValue(pos);
    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint32 dur){
        ui->VolumeMediaDisplay->setMaximum(dur);
    });
}

Soundsetting::~Soundsetting()
{
    delete ui;
}

void Soundsetting::on_MuteMedia_clicked()
{
    if(ui->MuteMedia->text()=="Mute")
    {
        mMediaPlayer->setMuted(true);
        ui->MuteMedia->setText("Unmute");
    }else{
        mMediaPlayer->setMuted(false);
        ui->MuteMedia->setText("Mute");
    }

}

void Soundsetting::on_StopMedia_clicked()
{
    mMediaPlayer->stop();
}

void Soundsetting::on_PauseMedia_clicked()
{
    mMediaPlayer->pause();
}

void Soundsetting::on_PlayMedia_clicked()
{
    mMediaPlayer->play();
}

void Soundsetting::on_OpenMedia_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"OpenMedia");
    if(filename.isEmpty())
    {
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->VolumeMediaControl->value());
    on_PlayMedia_clicked();
}

void Soundsetting::on_VolumeMediaControl_valueChanged(int value)
{

    ui->VolumeMediaDisplay->setValue(value);
    mMediaPlayer->setVolume(value);

}

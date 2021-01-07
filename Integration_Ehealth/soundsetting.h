#ifndef SOUNDSETTING_H
#define SOUNDSETTING_H
#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class Soundsetting;
}
class QMediaPlayer;
class Soundsetting : public QDialog
{
    Q_OBJECT

public:
    explicit Soundsetting(QWidget *parent = nullptr);
    ~Soundsetting();

private slots:
    void on_MuteMedia_clicked();

    void on_StopMedia_clicked();

    void on_PauseMedia_clicked();

    void on_PlayMedia_clicked();

    void on_OpenMedia_clicked();

    void on_VolumeMediaControl_valueChanged(int value);

private:
    Ui::Soundsetting *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // SOUNDSETTING_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QUdpSocket;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QByteArray *data;
    //QNetworkDatagram *datagram;
    QUdpSocket *MyUdpSocket;
    QUdpSocket *MyUdpSocket1;
    QUdpSocket *MyUdpSocket2;
    QUdpSocket *MyUdpSocket3;





private:
    Ui::MainWindow *ui;


private slots:
    void text_numbers();
    void point();
    void percent();
    void math();
    void equal();
    void allclear();
    void plus_minus();
    void on_pushButton_plus_clicked();
    //void on_pushButton_equal_clicked();
    //void on_pushButton_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_star_clicked();
    void on_pushButton_slash_clicked();
    void on_pushButton_elevate_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_percent_clicked();
};
#endif // MAINWINDOW_H

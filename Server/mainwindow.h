#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}
class QUdpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QUdpSocket *MyUdpSocket;
    QUdpSocket *MyUdpSocket1;
    QUdpSocket *MyUdpSocket2;
    QUdpSocket *MyUdpSocket3;
private slots:
    //void initSocket();
    //void readPendingDatagrams();
    //void processTheDatagram(QNetworkDatagram &datagram);
    //void on_pushButton_clicked();
};

#endif // MAINWINDOW_H

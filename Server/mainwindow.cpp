#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>
#include "QDebug"
#include "cmath"

double First_num, Sec_num;
double newVariable;
QString sym1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyUdpSocket2 = new QUdpSocket(this);

    //MyUdpSocket->abort();
    MyUdpSocket = new QUdpSocket(this);

    MyUdpSocket->bind(QHostAddress::LocalHost, 1234);
    connect(MyUdpSocket, &QUdpSocket::readyRead, [&]()
    {
        if(MyUdpSocket->hasPendingDatagrams())
        {
            QByteArray datagrama;
            datagrama.resize(MyUdpSocket->pendingDatagramSize());
            MyUdpSocket->readDatagram(datagrama.data(), datagrama.size());
            //ui->textEdit->addItem(QString(datagrama));
            ui->text_edit->setText(QString(datagrama));
            First_num = datagrama.toDouble();
        }
    });

    MyUdpSocket1 = new QUdpSocket(this);
    MyUdpSocket1->bind(QHostAddress::LocalHost, 2234);
    connect(MyUdpSocket1, &QUdpSocket::readyRead, [&]()
    {
        if(MyUdpSocket1->hasPendingDatagrams())
        {
            QByteArray datagrama1;
            datagrama1.resize(MyUdpSocket1->pendingDatagramSize());
            MyUdpSocket1->readDatagram(datagrama1.data(), datagrama1.size());
            //ui->textEdit->addItem(QString(datagrama));
            ui->text_edit->setText(QString(datagrama1));
            Sec_num = datagrama1.toDouble();

            if(sym1 == "1")
            {
                newVariable = First_num + Sec_num;
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
            else if(sym1 == "2")
            {
                newVariable = First_num - Sec_num;
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
            else if(sym1 == "3")
            {
                newVariable = First_num * Sec_num;
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
            else if(sym1 == "4")
            {
                newVariable = First_num / Sec_num;
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
            else if(sym1 == "5")
            {
                //variableNumber = std::pow(first_num, sec_num);
                newVariable = std::pow(First_num, Sec_num);
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
            else if(sym1 == "6")
            {
                if(First_num < 0)
                {
                  ui->label->setText("Error");

                    auto datagrama2 = ui->label->text().toLatin1();
                    MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
                }
                else
                {
                    newVariable = std::sqrt(First_num);
                    ui->label->setNum(newVariable);

                    auto datagrama2 = ui->label->text().toLatin1();
                    MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
                }
            }
            else if(sym1 == "7")
            {

                newVariable = First_num * 0.01;
                ui->label->setNum(newVariable);

                auto datagrama2 = ui->label->text().toLatin1();
                MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
            }
        }
    });

    MyUdpSocket3 = new QUdpSocket(this);
    MyUdpSocket3->bind(QHostAddress::LocalHost, 4234);
    connect(MyUdpSocket3, &QUdpSocket::readyRead, [&]()
    {
        if(MyUdpSocket3->hasPendingDatagrams())
        {
            QByteArray datagrama3;
            datagrama3.resize(MyUdpSocket3->pendingDatagramSize());
            MyUdpSocket3->readDatagram(datagrama3.data(), datagrama3.size());
            sym1 = datagrama3;
            //qDebug()<<sym1;

        }
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::readPendingDatagrams()
{
    while(MyUdpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = MyUdpSocket->receiveDatagram();
        processTheDatagram(datagram);
    }
}




void MainWindow::processTheDatagram(QNetworkDatagram &datagram)
{
    qDebug()<<datagram.data();
}
*/

/*void MainWindow::on_pushButton_clicked()
{
    qDebug()<<First_num;
    qDebug()<<Sec_num;

    qDebug()<<"разделение";
    newVariable = First_num + Sec_num;
    qDebug()<<newVariable;
    //ui->text_edit->
    ui->label->setNum(newVariable);
    //auto datagrama1 =;
    auto datagrama2 = ui->label->text().toLatin1();
    MyUdpSocket2->writeDatagram(datagrama2, QHostAddress::LocalHost, 3234);
    ui->text_edit->setText("0");
}*/



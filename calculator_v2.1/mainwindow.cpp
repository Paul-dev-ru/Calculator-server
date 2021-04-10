#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "cmath"
#include "QMessageBox"
#include <QUdpSocket>

double first_num, ans;
bool trigger = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyUdpSocket = new QUdpSocket(this);
    MyUdpSocket1 = new QUdpSocket(this);
    MyUdpSocket3 = new QUdpSocket(this);

    MyUdpSocket2 = new QUdpSocket(this);
    MyUdpSocket2->bind(QHostAddress::LocalHost, 3234);
    connect(MyUdpSocket2, &QUdpSocket::readyRead, [&]()
    {
        if(MyUdpSocket2->hasPendingDatagrams())
        {
            QByteArray datagrama2;
            datagrama2.resize(MyUdpSocket2->pendingDatagramSize());
            MyUdpSocket2->readDatagram(datagrama2.data(), datagrama2.size());
            ui->text_numbers->setText(QString(datagrama2));
            //ans = datagrama2.toDouble();

            //qDebug()<<"text";
            //qDebug()<<ans;
        }
    });

    connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_eight, SIGNAL(clicked()), this, SLOT(text_numbers()));
    connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(text_numbers()));

    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(percent()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(plus_minus()));

    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(point()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_star, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_slash, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_elevate, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(math()));

    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal()));

    connect(ui->pushButton_allclear, SIGNAL(clicked()), this, SLOT(allclear()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_star->setCheckable(true);
    ui->pushButton_slash->setCheckable(true);
    ui->pushButton_sqrt->setCheckable(true);
    ui->pushButton_elevate->setCheckable(true);
    ui->pushButton_allclear->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::sendPendingDatagrams(QByteArray &data)
{
    QNetworkDatagram datagram;
    datagram.setDestination (QHostAddress::LocalHost, 8877);
    datagram.setData(data);
    MyUdpSocket->writeDatagram(datagram);
}*/

void MainWindow::text_numbers()
{
    //qDebug()<<"text";

    QPushButton *button = (QPushButton *)sender();

    double variableNumber;
    QString newVariable;
    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_star->isChecked()
            || ui->pushButton_slash->isChecked() || ui->pushButton_elevate->isChecked()) && (!(trigger)))
    {
        variableNumber = button->text().toDouble();
        trigger = true;
        newVariable = QString::number(variableNumber, 'g', 12);

    }
    else
    {
        if((ui->text_numbers->text().contains('.')) && (button->text() == "0"))
        {
            newVariable = ui->text_numbers->text() + button -> text();
        }
        else
        {
            variableNumber = ( ui->text_numbers->text() + button->text()).toDouble();
            newVariable = QString::number(variableNumber, 'g', 12);
        }
    }


    ui->text_numbers->setText(newVariable);
}
void MainWindow::math()
{



    QPushButton *button = (QPushButton *)sender();
    first_num = ui->text_numbers->text().toDouble();

    if (button->text() == "+")
    {

        ui->text_numbers->setText("+");
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
       //ui->pushButton_plus_minus->setEnabled(false);
        ui->pushButton_percent->setEnabled(false);
       //ui->pushButton_equal->setEnabled(false);

    }
    else if (button->text() == "-")
    {

        ui->text_numbers->setText("-");
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
        //ui->pushButton_plus_minus->setEnabled(false);
         ui->pushButton_percent->setEnabled(false);
        //ui->pushButton_equal->setEnabled(false);

    }
    else if (button->text() == "*")
    {

        ui->text_numbers->setText("*");
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
        //ui->pushButton_plus_minus->setEnabled(false);
         ui->pushButton_percent->setEnabled(false);
        //ui->pushButton_equal->setEnabled(false);
    }
    else if (button->text() == "/")
    {

        ui->text_numbers->setText("/");
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
        //ui->pushButton_plus_minus->setEnabled(false);
        ui->pushButton_percent->setEnabled(false);
        //ui->pushButton_equal->setEnabled(false);
    }
    else if (button->text() == "x^y")
    {

        ui->text_numbers->setText("^");
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
        //ui->pushButton_plus_minus->setEnabled(false);
        ui->pushButton_percent->setEnabled(false);
        //ui->pushButton_equal->setEnabled(false);
    }
    else if (button->text() == "sqrt")
    {
        ui->text_numbers->setText("sqrt");

        ui->pushButton_zero->setEnabled(false);
        ui->pushButton_one->setEnabled(false);
        ui->pushButton_two->setEnabled(false);
        ui->pushButton_three->setEnabled(false);
        ui->pushButton_four->setEnabled(false);
        ui->pushButton_five->setEnabled(false);
        ui->pushButton_six->setEnabled(false);
        ui->pushButton_seven->setEnabled(false);
        ui->pushButton_eight->setEnabled(false);
        ui->pushButton_nine->setEnabled(false);

        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_minus->setEnabled(false);
        ui->pushButton_star->setEnabled(false);
        ui->pushButton_slash->setEnabled(false);
        ui->pushButton_elevate->setEnabled(false);
        ui->pushButton_sqrt->setEnabled(false);
        ui->pushButton_point->setEnabled(false);
        //ui->pushButton_plus_minus->setEnabled(false);
        ui->pushButton_percent->setEnabled(false);
        //ui->pushButton_equal->setEnabled(false);
    }

    button->setChecked(true);

}
void MainWindow::point()
{
    //if(!(ui->text_numbers->text().contains('.')))
    //{
    //    ui->text_numbers->setText(ui->text_numbers->text() + '.');
    //}

    if(ui->text_numbers->text() == "+" || ui->text_numbers->text() == "-" || ui->text_numbers->text().contains('*')
            || ui->text_numbers->text().contains('/') || ui->text_numbers->text().contains('^') || ui->text_numbers->text().contains("sqrt"))
    {
        QMessageBox::warning(this, "Предупреждение", "Сначала завершите операцию");
    }
    else
    {
        //ui->text_numbers->setText(ui->text_numbers->text() + '.');
        if(!(ui->text_numbers->text().contains('.')))
        {
            ui->text_numbers->setText(ui->text_numbers->text() + '.');
        }

    }

}

void MainWindow::percent()
{
    QPushButton *button = (QPushButton *)sender();

    double variableNumber;
    QString newVariable;

    if(ui->text_numbers->text() == "+" || ui->text_numbers->text() == "-" || ui->text_numbers->text().contains('*')
            || ui->text_numbers->text().contains('/') || ui->text_numbers->text().contains('^') || ui->text_numbers->text().contains("sqrt"))
    {
        QMessageBox::warning(this, "Предупреждение", "Сначала завершите операцию");
    }
    else
    {
        //ui->text_numbers->setText(ui->text_numbers->text() + '.');
        if(button->text() == "%")
            {
                variableNumber = (ui->text_numbers->text()).toDouble();
                variableNumber = variableNumber * 0.01;
                newVariable = QString::number(variableNumber, 'g', 12);

                ui->text_numbers->setText(newVariable);

            }

    }
}
void MainWindow::plus_minus()
{
    QPushButton *button = (QPushButton *)sender();

    double variableNumber;
    QString newVariable;

    if(ui->text_numbers->text() == "+" || ui->text_numbers->text() == "-" || ui->text_numbers->text().contains('*')
            || ui->text_numbers->text().contains('/') || ui->text_numbers->text().contains('^') || ui->text_numbers->text().contains("sqrt"))
    {
        QMessageBox::warning(this, "Предупреждение", "Сначала завершите операцию");
    }
    else
    {
        if(button->text() == "+/-")
            {
                variableNumber = (ui->text_numbers->text()).toDouble();
                variableNumber = variableNumber * -1;
                newVariable = QString::number(variableNumber, 'g', 12);

                ui->text_numbers->setText(newVariable);

            }

     }

    /*if(button->text() == "+/-")
    {
        labelnumber = (ui->text_numbers->text()).toDouble();
        labelnumber = labelnumber * -1;
        newLabel = QString::number(labelnumber, 'g', 12);

        ui->text_numbers->setText(newLabel);

    }*/
}
void MainWindow::equal()
{
    double sec_num;
    sec_num = ui->text_numbers->text().toDouble();


    if (ui->pushButton_plus->isChecked())
    {

        ui->pushButton_plus->setChecked(false);

    }

    else if(ui->pushButton_minus->isChecked())
    {

        ui->pushButton_minus->setChecked(false);
    }

    else if(ui->pushButton_star->isChecked())
    {

        ui->pushButton_star->setChecked(false);
    }

    else if(ui->pushButton_slash->isChecked())
    {

        ui->pushButton_slash->setChecked(false);
    }

    if (ui->pushButton_sqrt->isChecked())
    {

        ui->pushButton_sqrt->setChecked(false);
    }
    

    if (ui->pushButton_elevate->isChecked())
    {

        ui->pushButton_elevate->setChecked(false);
    }

    auto datagrama1 = ui->text_numbers->text().toLatin1();
    MyUdpSocket1->writeDatagram(datagrama1, QHostAddress::LocalHost, 2234);

    ui->pushButton_zero->setEnabled(true);
    ui->pushButton_one->setEnabled(true);
    ui->pushButton_two->setEnabled(true); 
    ui->pushButton_three->setEnabled(true);
    ui->pushButton_four->setEnabled(true);
    ui->pushButton_five->setEnabled(true);
    ui->pushButton_six->setEnabled(true);
    ui->pushButton_seven->setEnabled(true);
    ui->pushButton_eight->setEnabled(true);
    ui->pushButton_nine->setEnabled(true);

    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
    ui->pushButton_star->setEnabled(true);
    ui->pushButton_slash->setEnabled(true);
    ui->pushButton_elevate->setEnabled(true);
    ui->pushButton_sqrt->setEnabled(true);
    ui->pushButton_point->setEnabled(true);

     trigger = false;
}
void MainWindow::allclear()
{

    ui->pushButton_zero->setEnabled(true);
    ui->pushButton_one->setEnabled(true);
    ui->pushButton_two->setEnabled(true);
    ui->pushButton_three->setEnabled(true);
    ui->pushButton_four->setEnabled(true);
    ui->pushButton_five->setEnabled(true);
    ui->pushButton_six->setEnabled(true);
    ui->pushButton_seven->setEnabled(true);
    ui->pushButton_eight->setEnabled(true);
    ui->pushButton_nine->setEnabled(true);

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_star->setChecked(false);
    ui->pushButton_slash->setChecked(false);
    ui->pushButton_elevate->setChecked(false);
    ui->pushButton_sqrt->setChecked(false);

    ui->pushButton_plus->setEnabled(true);
    ui->pushButton_minus->setEnabled(true);
    ui->pushButton_star->setEnabled(true);
    ui->pushButton_slash->setEnabled(true);
    ui->pushButton_elevate->setEnabled(true);
    ui->pushButton_sqrt->setEnabled(true);
    //ui->pushButton_plus_minus->setEnabled(false);
    //ui->pushButton_percent->setEnabled(false);
    //ui->pushButton_equal->setEnabled(true);

    ui->text_numbers->setText("0");
}

void MainWindow::on_pushButton_plus_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "1";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}


void MainWindow::on_pushButton_minus_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "2";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

void MainWindow::on_pushButton_star_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "3";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

void MainWindow::on_pushButton_slash_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "4";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

void MainWindow::on_pushButton_elevate_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "5";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "6";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

void MainWindow::on_pushButton_percent_clicked()
{
    auto datagrama = ui->text_numbers->text().toLatin1();
    MyUdpSocket->writeDatagram(datagrama, QHostAddress::LocalHost, 1234);
    QByteArray sym = "7";
    auto datagrama3 = sym;
    MyUdpSocket3->writeDatagram(datagrama3, QHostAddress::LocalHost, 4234);
}

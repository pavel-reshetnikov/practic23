#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->comboBox->addItem("asd",1);
    p1.name = "Кукурузник";
    p1.speed = 200;
    f.FlightEvent.speed_effect = 25;
    f.FlightEvent.chance = 30;
    f.FlightEvent.name = "Плохая погода";
    r1.name = "Город1 - Город2";
    r1.x1 = 0;
    r1.y1 = 0;
    r1.x2 = 3000;
    r1.y2 = 4000;

    p2.name = "Миг";
    p2.speed = 400;
    r2.name = "Город2 - Город3";
    r2.x1 = 3000;
    r2.y1 = 4000;
    r2.x2 = 6000;
    r2.y2 = 2000;
ui->comboBox->addItem(p1.name,0);
ui->comboBox->addItem(p2.name,0);
ui->comboBox_2->addItem(r1.name,0);
ui->comboBox_2->addItem(r2.name,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    switch(ui->comboBox->currentIndex()){
    case 0:
        f.Plane = p1;
        ui->label->setText(QString::number(p.speed));
                break;
    case 1:
        f.Plane = p2;
        break;

    }
    switch(ui->comboBox_2->currentIndex()){
    case 0:
        f.Route = r1;
                break;
    case 1:
        f.Route = r2;
        break;

    }
    ui->label_2->setText(QString::number(f.Plane.speed));
    ui->label_3->setText(QString::number(f.Route.lenght()));
     ui->label->setText(QString::number(f.go()));
}


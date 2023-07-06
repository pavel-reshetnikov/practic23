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
    fe1.name = "Плохая погода";
    fe1.speed_effect = 25;
    fe1.chance = 25;
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

    /*f.setPlane(p1,"Кукурузник",200);
    f.setFlightEvent(fe1,"Плохая погода", 20,10);
    f.setRoute(r1,"Город1-Город2",0,0,3000,4000);
    f.go(p1, r1, fe1);*/
    switch(ui->comboBox->currentIndex()){
    case 0:
        p = p1;
        ui->label->setText(QString::number(p.speed));
                break;
    case 1:
        p = p2;
        break;

    }
    switch(ui->comboBox_2->currentIndex()){
    case 0:
        r = r1;
                break;
    case 1:
        r = r2;
        break;

    }
    ui->label_2->setText(QString::number(p.speed));
    ui->label_3->setText(QString::number(r.lenght()));
     ui->label->setText(QString::number(f.go(p, r, fe1)));
}


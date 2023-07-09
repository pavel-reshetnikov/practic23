#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class plane{
public:
    QString name;
    int speed;
};


class route{
public:
    QString name;
    int x1; //координаты точки
    int y1;
    int x2;
    int y2;

    int lenght(){
      int x = x2 - x1;
      int y = y2 - y1;
      return sqrt(x*x+y*y);
    };
};


class flightEvent{
    public:
    flightEvent(){
        name = "";
        chance=0;
        speed_effect=0;
    };

    QString name;
    int chance;
    int speed_effect;

    int trigger(){
      int randNum = rand()%100;
      if(chance > randNum){
          qDebug()<<"Произошло проишествие: " << name<<" Скорость снижена на"<< speed_effect<<"%";
          return 100-speed_effect;}
      return 100;
    };
};


class facade{
public:
    plane Plane;
    route Route;
    flightEvent FlightEvent;
    int go(){
        int time = Route.lenght() / ((Plane.speed * FlightEvent.trigger())/100);
        qDebug()<< "Время пути: "<<time;
        return time;
    }
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    facade f;
    plane p1;
    flightEvent fe1;
    route r1;
    plane p2;
    route r2;
    plane p;
    route r;
private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
};






#endif // MAINWINDOW_H

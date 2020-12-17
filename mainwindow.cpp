#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   h_limit = 2000;
   v_limit = 1000;
   dt = 0.1;

   timer = new QTimer(this);
   scene = new QGraphicsScene(this);
   scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);

   ui->graphicsView->setScene(scene);
   ui->centralwidget->adjustSize();

   timer->stop();
   connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{
    for(int i=0; i<bars.size();i++){
        for(int j=0; j<bars.size();j++){
            if(i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPx(),bars.at(j)->getEsf()->getPy(),bars.at(j)->getEsf()->getMasa());
                bars.at(i)->actualizar(dt);
            }

        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    timer->start(dt);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(bars.size()<planetas){
        if(ui->radioButton->isChecked())
            Color=1;
        if(ui->radioButton_3->isChecked())
            Color=2;
        if(ui->radioButton_2->isChecked())
            Color=3;
        if(ui->radioButton_5->isChecked())
            Color=4;
        if(ui->radioButton_4->isChecked())
            Color=5;
        if(ui->radioButton_6->isChecked())
            Color=6;

        bars.append(new cuerpograph(ui->doubleSpinBox_2->value(),ui->doubleSpinBox_3->value(),ui->doubleSpinBox_4->value(),ui->doubleSpinBox_5->value(),ui->doubleSpinBox_6->value(),ui->doubleSpinBox_7->value(),Color));
        scene->addItem(bars.back());
        bars.back()->actualizar(0);
    }
    else{
        msgBox.setText("Excede el número de planetas solicitados.");
        msgBox.exec();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->spinBox->value()>0){
        planetas = ui->spinBox->value();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    for(int i=0;i<bars.size();i++){
        scene->removeItem(bars.at(i));
        bars.removeAt(i);
    }
    msgBox.setText("Pantalla limpia.");
    msgBox.exec();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar(){
    this->myWidget.setNum(ui->spinBox->value());
    this->myWidget.setConst(ui->doubleSpinBox->value());
    this->myWidget.setIter(ui->spinBox_2->value());
    this->myWidget.repaint();
}

void MainWindow::controlRadioButton1()
{
    if(this->ui->radioButton->isChecked()) this->ui->radioButton_2->setChecked(false);
    else this->ui->radioButton_2->setChecked(true);
}

void MainWindow::controlRadioButton2()
{
    if(this->ui->radioButton_2->isChecked()) this->ui->radioButton_2->setChecked(false);
    else this->ui->radioButton->setChecked(true);
}

void MainWindow::salir(){
    exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    actualizar();
}

void MainWindow::on_pushButton_2_clicked()
{
    salir();
}

void MainWindow::on_radioButton_clicked()
{
    this->controlRadioButton2();
    this->myWidget.set3D(12);
}

void MainWindow::on_radioButton_2_clicked()
{
    this->controlRadioButton1();
    this->myWidget.set3D(0);
}

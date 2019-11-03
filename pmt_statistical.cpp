#include "pmt_statistical.h"
#include "ui_pmt_statistical.h"
#include "QMessageBox"

pmt_statistical::pmt_statistical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pmt_statistical)
{
    ui->setupUi(this);
    //neighbour_number_=atoi(ui->lineEdit->text().toStdString().c_str());
    //std_multiple_threshould_=atof(ui->lineEdit->text().toStdString().c_str());

    neighbour_number_=30;
    std_multiple_threshould_=10.0;
    ui->lineEdit->setText(QString::number(neighbour_number_));
    ui->lineEdit_2->setText(QString::number(std_multiple_threshould_));
}

pmt_statistical::~pmt_statistical()
{
    delete ui;
}

void pmt_statistical::on_pushButton_2_clicked()
{
    neighbour_number_=atoi(ui->lineEdit->text().toStdString().c_str());
    std_multiple_threshould_=atof(ui->lineEdit->text().toStdString().c_str());
}

void pmt_statistical::on_pushButton_3_clicked()
{
     this->close();
}

void pmt_statistical::on_pushButton_clicked()
{
    ui->lineEdit->setText("30");
    ui->lineEdit_2->setText("10.0");
}

#include "gui_outlier_removal.h"
#include "ui_gui_outlier_removal.h"

gui_outlier_removal::gui_outlier_removal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gui_outlier_removal)
{
    ui->setupUi(this);
    k_nearest_=5;
    nSigma_=2.1f;
    ui->lineEdit->setText(QString::number(k_nearest_));
    ui->lineEdit_2->setText(QString("%1").arg(nSigma_));
}

gui_outlier_removal::~gui_outlier_removal()
{
    delete ui;
}

void gui_outlier_removal::on_pushButton_clicked()
{

}

// OK
void gui_outlier_removal::on_pushButton_2_clicked()
{
    k_nearest_=ui->lineEdit->text().toInt();
    nSigma_=ui->lineEdit_2->text().toFloat();
    emit SendStatisticalParameter(k_nearest_,nSigma_);
    this->close();
}

void gui_outlier_removal::on_pushButton_3_clicked()
{
    this->close();
}

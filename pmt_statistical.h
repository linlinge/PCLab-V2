#ifndef PMT_STATISTICAL_H
#define PMT_STATISTICAL_H

#include <QDialog>

namespace Ui {
class pmt_statistical;
}

class pmt_statistical : public QDialog
{
    Q_OBJECT

public:
    int neighbour_number_;
    float std_multiple_threshould_;

    explicit pmt_statistical(QWidget *parent = 0);
    ~pmt_statistical();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::pmt_statistical *ui;
};

#endif // PMT_STATISTICAL_H

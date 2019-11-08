#ifndef GUI_OUTLIER_REMOVAL_H
#define GUI_OUTLIER_REMOVAL_H

#include <QDialog>
#include "global.h"

namespace Ui {
class gui_outlier_removal;
}

class gui_outlier_removal : public QDialog
{
    Q_OBJECT

public:
    int k_nearest_;
    float nSigma_;
    explicit gui_outlier_removal(QWidget *parent = 0);
    ~gui_outlier_removal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gui_outlier_removal *ui;

signals:
    void SendStatisticalParameter(int k,float nSigma);
};

#endif // GUI_OUTLIER_REMOVAL_H

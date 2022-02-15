#ifndef INPUT_H
#define INPUT_H

#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlTableModel>
#include"mainwindow.h"
namespace Ui {
class Input;
}

class Input : public QMainWindow
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = nullptr);
    ~Input();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Input *ui;
     QSqlDatabase db;//переменная для работы с БД
      MainWindow *w; //храним новую форму как поле этой для корректной работы
};

#endif // INPUT_H

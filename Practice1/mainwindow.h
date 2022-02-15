#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlTableModel>
#include"abitur.h"
#include "exam.h"
#include "documents.h"
#include "napr.h"
#include<QTimer>
#include <QFile>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();
    void updateTime();  //слот для обновления данных
    void on_test_clicked();


    void on_delete_2_clicked();

private:
    Ui::MainWindow *ui;
      QSqlDatabase db;//переменная для работы с БД
      void DataBase_1();
       QTimer *tmr;    //ссылка на таймер
};

#endif // MAINWINDOW_H


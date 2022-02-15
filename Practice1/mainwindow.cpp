#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //подключаемся к базе данных
    try {
        db = QSqlDatabase::addDatabase("QSQLITE");
        //проект должен лежать в указанной папке
        db.setDatabaseName("D:\\project\\release\\qt.db");
        db.open();
    } catch (QString Error) {
        Error = "Ошибка БД";
        ui->Block->setText(Error);
    }
    tmr = new QTimer();//создаем новый таймер
    tmr->setInterval(50);//данные обновляются 20 раз в секнду
    //Соединим сигнал timeout() таймера tmr со слотом updateTime() объекта класса MainWindow
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));

    //и запустим таймер
    tmr->start();
    // таймер 20 раз в секунду обновляет всю информацию 
}

MainWindow::~MainWindow()
{
    delete ui;
}

//обновление информации по таймеру
void MainWindow::updateTime(){
    DataBase_1();
}
void MainWindow::on_pushButton_2_clicked()
{
Abitur Boria;
Documents Artem;
Exam Sasha;
Napr Dima;
Boria.set_Sg_g(ui->FIO->text());
Boria.set_Age((ui->AGE->text()).toInt());
Boria.set_Num_of_pas(ui->PAS->text());
Artem.set_Napr(ui->NAPR->text());
Artem.set_Date_of_application(ui->DATE->text());
Sasha.set_Time_of_exam(ui->EXAM->text());
Sasha.set_Coints((ui->COINTS->text()));
Dima.set_Num_of_Statement(ui->NUM->text());
try {
    QSqlQuery query3;//в этой переменной храним запрос к БД
    QString qur2 =
            "INSERT INTO List(ABITUR, DOCUMENTS, EXAM, Num_of_statment)"
            " VALUES ('" + Boria.getSobr() +
            "', '" + Artem.getSobr() + "', '" + Sasha.getSobr() +"','"+Dima.getSobr()+"')";  //формируем запрос
    query3.exec(qur2);//отправляем его в БД
//    ui->FIO->clear();
//     ui->AGE->clear();
//      ui->PAS->clear();
//       ui->NAPR->clear();
//        ui->DATE->clear();
//         ui->EXAM->clear();
//          ui->COINTS->clear();
//           ui->NUM->clear();


}
catch (QString Error) {
    Error = "Ошибка БД";
    ui->label->setText(Error);
}

}
void MainWindow::DataBase_1(){

    //очищаем предыдущую информацию
    ui->listWidget->clear();

    QString str = "";

    QString abitur, exam, documents,num;


    //берем данные из БД
    try {
        QSqlQuery query;//в этой переменной храним запрос к БД
        query.exec("SELECT ABITUR, EXAM, DOCUMENTS, Num_of_statment FROM List");

        //данные
        while (query.next())
        {
        abitur = query.value(0).toString();
        exam = query.value(1).toString();
        documents = query.value(2).toString();
        num = query.value(3).toString();


        str+= + "  |  " + abitur+ "  |  " +exam +  "  |  "  + documents+ "  |  " + num+ "  |  ";

        //добавляем новую строку в список
        ui->listWidget->addItem(str);
        str = "";
        }
    }
    catch(QString Error){
        Error = "Ошибка подключения к БД!";
      ui->label_2->setText("Error");
    }

}




void MainWindow::on_test_clicked()
{
    try {
        //для правильного чтения русских символов файл должен быть в кодировке UTF-8
        QString adress = ui->adress->text();
        QFile file(adress);

        if (!file.open(QIODevice::ReadOnly))
            throw 1;
        int count = 0;
        while (!file.atEnd())
        {
             QByteArray line = file.readLine();
             QString str = line.data();// <- прочитанная строка

             //устанавливаем ФИО
             if (count == 0){
                 ui->FIO->setText(str);
                 count++;
             }
             //устанавливаем возраст
             else if(count == 1) {
                 ui->AGE->setText(str);
                 count++;
             }
             //устанавливаем номер и серию паспорта
             else if(count == 2){
                {
                 ui->PAS->setText(str);
                 }
                 count++;
             }
             //устанавливаем экзамены
             else if(count == 3) {
                 ui->EXAM->setText(str);
                 count++;
             }
             //устанавливаем баллы по экзаменам
             else if(count == 4) {
                 ui->COINTS->setText(str);
                 count++;
             }
             //устанавливаем  номер заявления
             else if(count == 5) {
                 ui->NUM->setText(str);
                 count++;
             }
             //устанавливаем направление
             else if(count == 6) {
                 ui->NAPR->setText(str);
                 count++;
             }
             //устанавливаем дату подачи заявления
             else if(count == 7) {
                 ui->DATE->setText(str);
                 count++;
             }
        }


    } catch (int err) {
        err = 0;
        ui->Block->setText("Ошибка чтения файла");
        return;
    }

}

void MainWindow::on_delete_2_clicked()
{


        QSqlQuery query;//в этой переменной храним запрос к БД
        QString del = ui->del->text();
        query.exec("delete from list where Num_of_statment =" + del);

}








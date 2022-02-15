#ifndef ABITUR_H
#define ABITUR_H
#include <QString>

class Abitur
{

private:
    QString Name; //ФИО студента
    int Age;//возраст студента
    QString Num_of_pas; //номер паспорта
public:

    //Конструктор
        Abitur();
        //Задать одно поле
        void set_Sg_g(QString name) { StrFormat(name); Name = name; }
        void set_Age(int age) { Age = age; }
        void set_Num_of_pas(QString pas) { Num_of_pas = pas; }
        //Вернуть поле

        QString get_name() { return Name; }
        int get_age() { return Age; }
        QString get_Num_of_Pas() { return Num_of_pas; }
        //Дополнительные операции
        void StrFormat(QString& str); //Форматирование "Первая" заглавная, остальны строчные

        QString getSobr();
};


#endif // ABITUR_H

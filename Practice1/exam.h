#ifndef EXAM_H
#define EXAM_H
#include <QString>

class Exam
{
private:

    QString Time_of_pass;//время сдачи
    QString Coints;
public:
    //Конструктор
    Exam();
    //Задать одно поле


    void set_Time_of_exam(QString time) { Time_of_pass = time; }
    void set_Coints(QString coints) {Coints = coints; }
    //Вернуть поле


    QString Time_of_exam() { return Time_of_pass; }
    QString get_Coints() {return Coints; }
    void StrFormat(QString& str); //Форматирование "Первая" заглавная, остальные строчные

    QString getSobr();
};

#endif // EXAM_H

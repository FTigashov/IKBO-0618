#include "exam.h"

Exam::Exam()
{

}
void Exam::StrFormat(QString &str)
    {
        if (str.isEmpty()) return;
        str[0] = str[0].toUpper();
        for (int i = 1; i < str.length(); i++) str[i] = str[i].toLower();
    }
QString Exam::getSobr()
{
    QString estr= Time_of_pass+" "+Coints;
    return estr;
}

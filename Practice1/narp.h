#ifndef NAPR_H
#define NAPR_H
#include <QString>

class Napr
{
private:
     QString Num_of_statement;//номер заявления
public:
    Napr();
     void set_Num_of_Statement(QString sta) {Num_of_statement = sta; }
      QString get_Num_of_statement() { return Num_of_statement; }
      QString getSobr();
};

#endif // NAPR_H

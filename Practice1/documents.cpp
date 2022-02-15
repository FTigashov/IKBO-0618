#include "documents.h"

Documents::Documents()
{

}
QString Documents::getSobr()
{
    QString dstr= Napr+" "+Date_of_application;
    return dstr;
}


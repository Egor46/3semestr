#include "Discipline.h"

Discipline::Discipline(string pFIO, int pgroup_num, string pwhatwhen, string pwhere)
{
    FIO = pFIO;
    group_number = pgroup_num;
    whatwhen = pwhatwhen;
    where = pwhere;
}

bool Discipline::are_compatible(Discipline y)
{
    return whatwhen == y.get_whatwhen();
}

void Discipline::unite_dis(Discipline y)
{
    FIO = y.get_FIO();
    where = y.get_where();

}

Discipline Discipline::new_disc(string pFIO, string pwhatwhen, string pwhere)
{
    Discipline new_D(pFIO, group_number, pwhatwhen, pwhere);
    return new_D;
}

string Discipline::get_FIO()
{
    return FIO;
}

string Discipline::get_whatwhen()
{
    return whatwhen;
}

string Discipline::get_where()
{
    return where;
}

#pragma once
#include <string>

using namespace std;

class Discipline
{
private:
	string FIO;
	int group_number;
	string whatwhen;
	string where;

public:

	Discipline(string pFIO = "", int pgroup_num = 0, string pwhatwhen = "", string pwhere = "");
	bool are_compatible(Discipline y);
	void unite_dis(Discipline y);
	Discipline new_disc(string pFIO, string pwhatwhen, string pwhere);
	string get_FIO();
	string get_whatwhen();
	string get_where();


};
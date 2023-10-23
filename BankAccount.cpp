#include "BankAccount.h"

BankAccount::BankAccount(int id_num, string nme, double mney)
{
	id_number = id_num;
	name = nme;
	money = mney;
}

BankAccount::BankAccount(const BankAccount& cpy)
{
	id_number = cpy.id_number;
	name = cpy.name;
	money = cpy.money;
	std::cout << "copied" << endl;
}

BankAccount::~BankAccount()
{
	cout << "BA destructor" << endl;
}

void BankAccount::add_sub_money(double dm)
{
	money += dm;
}

double BankAccount::get_money()
{
	return money;
}

void BankAccount::set_money(double m)
{
	money = m;
}

BankAccount BankAccount::new_account()
{
	BankAccount new_acc(id_number, name, money);
	return new_acc;
}

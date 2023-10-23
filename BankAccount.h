#pragma once
#include <iostream>
#include <string>
#include "IntArray.h"
using namespace std;

class BankAccount
{
private:
	int id_number;
	string name;
	double money;

public:
	BankAccount(int id_num = 0, string nme = "", double mney = 0);
	BankAccount(const BankAccount& cpy);
	~BankAccount();
	IntArray a{};
	void add_sub_money(double dm);
	double get_money();
	void set_money(double m);
	BankAccount new_account();


};
#pragma once

class INTEGER
{
private:

	int a, b;


public:

	INTEGER(int pa = 0, int pb = 0);
	int get_a();
	int get_b();
	void add(INTEGER y);
	void sub(INTEGER y);
	INTEGER mult(INTEGER y);



};
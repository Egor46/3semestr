#pragma once

class BoolFunction
{
private:
	
	bool xd[4] = { 0 };

public:
	
	BoolFunction(bool x[4]);

	BoolFunction AND(BoolFunction b);
	BoolFunction OR(BoolFunction b);
	void NOT();
	bool func(bool a, bool b);

};


#pragma once
class DV
{
private:
	double I, R;

public:
	DV();
	DV(double i, double r);
	~DV();
	double getI();
	double getR();
	void setI(double i);
	void setR(double r);
	double Voltage() const;
	double ElectricPower() const;
	void SerialConnection(const DV& b);	
	DV ParallelConnection(const DV& b);
};


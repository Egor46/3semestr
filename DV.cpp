#include "DV.h"

DV::DV()
{
    I = 0;
    R = 0;
}

DV::DV(double i, double r)
{
    I = i;
    R = r;
}

DV::~DV() {
    return;
}

double DV::getI()
{
    return I;
}

double DV::getR()
{
    return R;
}

void DV::setI(double i)
{
    I = i;
}

void DV::setR(double r)
{
    R = r;
}

double DV::Voltage() const
{
    return I * R;
}

double DV::ElectricPower() const
{
    return Voltage() * I;
}

void DV::SerialConnection(const DV& b)
{
    double u = Voltage() + b.Voltage();
    R += b.R;
    I = u / R;
}

DV DV::ParallelConnection(const DV& b)
{
    DV res;
    res.I = I + b.I;
    res.R = (R * b.R) / (R + b.R);
    return res;
}

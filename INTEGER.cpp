#include "INTEGER.h"

INTEGER::INTEGER(int pa, int pb)
{
    a = pa;
    b = pb;
}

int INTEGER::get_a()
{
    return a;
}

int INTEGER::get_b()
{
    return b;
}

void INTEGER::add(INTEGER y)
{
    a = a + y.get_a();
    b = b + y.get_b();
}

void INTEGER::sub(INTEGER y)
{
    a = a - y.get_a();
    b = b - y.get_b();
}

INTEGER INTEGER::mult(INTEGER y)
{
    INTEGER c(a * y.get_a(), b * y.get_b());
    return c;
}

#include "arith"

int add(const int& a, const int& b)
{
    return a + b;
}

int sub(const int& a, const int& b)
{
    return a - b;
}

int mult(const int& a, const int& b)
{
    return a * b;
}

int div(const int& a, const int& b)
{
    return a / b;
}

int mod(const int& a, const int& b)
{
    return a % b;
}

int pre_inc(int& a)
{
    a = a+1;
    return a;
}

int pst_inc(int& a)
{
    int b = a;
    a = a + 1;
    return b;
}
#include "arith_macro"

#define A 10
#define B 5
#define C 2

int main()
{
    int w = ADD(A + B, C);
    int x = SUB(-A, 5 + 6);
    int y = PRE_INC(x);
    int z = PST_INC(y);
    return 0;
}

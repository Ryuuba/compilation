#if defined(MACRO)
#include "arith_macro.h"
#else
#include "arith.h"
#endif

int main()
{
    int x;
    #if defined(MACRO)
    x = ADD(5*6, 4);
    #else
    x = add(5*6, 4);
    #endif
    return 0;
}




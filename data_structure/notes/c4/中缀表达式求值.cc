#include <iostream>
#include <stack>

#define N_OPTR 9

const char pri[N_OPTR][N_OPTR] {
//  +    -    *    /    ^    !    (    )    \0
    '>','>', '<', '<', '<', '<', '<', '>', '>',
    '>','>', '<', '<', '<'
}


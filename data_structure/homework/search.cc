#include <iostream>
#include <list>
using namespace std;

list<int>::iterator search(int num,int n,list<int>::iterator p)
{
    while (n-- >= 0) {
        --p;
        if (num <= *p) break;
    }
    return p;
}


int main(void)
{
    return 0;
}

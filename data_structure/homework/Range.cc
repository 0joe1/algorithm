#include <iostream>
#include <list>

#define MAXN 1000000
using namespace std;
int s[MAXN];

//可能还有现成的库函数可以使用
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
    list<int> numbers;
    int n,m;
    cin >> n; cin >>m;

    //读入n个点坐标,排序
    int npos;
    list<int>::iterator p = numbers.end();
    list<int>::iterator np;
    for (int i = 0; i < n; i++)
    {
        cin >> npos;
        np = search(npos,i,p);
        list<int>::insert(np,npos)
    }


    return 0;
}

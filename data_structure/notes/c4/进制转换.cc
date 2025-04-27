#include <iostream>
#include <stack>
using namespace std;

void convert(stack<char>& s,int n,int base)
{
    static char digit[] = 
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F'};

    while (n)
    {
        s.push(digit[n%base]);
        n /= base;
    }
}

int main(void)
{
    int n,base;
    stack<char> s;
    cout << "请输入你想转换的数字与进制  ";
    scanf("%d %d",&n,&base);
    convert(s,n,base);
    while(!s.empty()) {
        cout << s.top() ;
        s.pop();
    }

    return 0;
}

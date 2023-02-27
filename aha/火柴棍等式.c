#include <stdio.h>

int fun(int x)
{
    int num=0;
    int f[10]={6,2,5,5,4,5,6,3,7,6};

    while (x/10 !=0)
    {
        num+=f[x%10];
        x=x/10;
    }
    num+=f[x];
    return num;
}
int main(void)
{
    int ans=0;

    for (int a=0;a<1111;a++)
    {
        for (int b=0;b<1111;b++)
        {
            int c = a+b;
            if (fun(a)+fun(b)+fun(c)+4 ==18)
            {
                printf("%d + %d = %d\n",a,b,c);
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
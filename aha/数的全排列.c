#include <stdio.h>

int a[100],book[100];
int n;

void dfs(int step)
{
    if (step == n){
        for (int i=0;i<n;i++)
            printf("%d",a[i]);
        printf("\n");
        return ;
    }
    for (int i=0;i<n;i++)
    {
        if (book[i] == 0)
        {
            a[step] = i;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return ;
}

int main(void)
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}
#include <stdio.h>
int e[10][10],match[10],book[10];
int n,m;

int dfs(int x)
{
    for (int i=0;i<n;i++)
    {
        if (book[i]==0 && e[x][i])
        {
            book[i]=1;
            if (match[i]==0 || dfs(match[i]))
            {
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        e[x][y]=1;
    }

    int count=0;
    for (int i=0;i<n;i++)
    {
        for (int i=0;i<n;i++)
            book[i]=0;
        if (dfs(i)) count++;
    }
    printf("%d",count);

    return 0;
}
/*
3 5
0 0
0 1
1 1
1 2
2 0
*/


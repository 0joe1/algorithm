#include <stdio.h>
int a[51][51];
int book[51][51],n,m,sum;

void dfs(int x,int y)
{
    int next[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    int dx,dy;
    for (int i=0;i<4;i++)
    {
        dx = x + next[i][0];
        dy = y + next[i][1];

        if (dx<0 || dx>n || dy<0 || dy>m)
            continue;
        if (!book[dx][dy] && a[dx][dy]>0)
        {
            sum++;
            book[dx][dy]=1;
            dfs(dx,dy);
        }
    }
}

int main(void)
{
    int startx,starty;
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    
    book[startx][starty] = 1;
    sum=1;
    dfs(startx,starty);
    printf("%d\n",sum);
    return 0;
}
/*
10 10 5 6
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 0 0*/
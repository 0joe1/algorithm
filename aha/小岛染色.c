#include <stdio.h>
int a[51][51];
int book[51][51],n,m;

void dfs(int x,int y,int color)
{
    a[x][y] = color;
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
            book[dx][dy]=1;
            dfs(dx,dy,color);
        }
    }
}

int main(void)
{
    int startx,starty;
    int color=0;
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]>0)
            {
                color--;
                book[i][j]=1;
                dfs(i,j,color);
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
    printf("有%d个小岛",-color);
    return 0;
}
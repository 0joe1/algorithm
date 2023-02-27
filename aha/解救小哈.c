#include <stdio.h>
int n,m,p,q,min=99999;
int a[51][51],book[51][51];

void dfs(int x,int y, int step)
{
    int next[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    if (x==p && y==q)
    {
        min = min<step?min:step;
        book[x][y]=0;
        return ;
    }
    for (int d=0;d<4;d++)
    {
        int dx = x+next[d][0];
        int dy = y+next[d][1];

        if (dx>=0 && dx<n && dy>=0 && dy<m && !book[dx][dy] && !a[dx][dy])
        {
            book[dx][dy] = 1;
            dfs(dx,dy,step+1);
            book[dx][dy] = 0;
        }
    }
    return;
}

int main(void)
{
    int i,j,startx,starty;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    book[startx][starty]=1;
    dfs(startx,starty,0);
    printf("%d",min);      
    return 0;
}
#include <stdio.h>
int a[51][51];
int book[51][51],n,m,flag=0;


struct pos{
    int x;
    int y;
}s[100];
int top=0;

_Bool isvalid(int x,int y){
    if (x>=0 && x<n && y>=0 && y<m && a[x][y]){
        return 1;
    }
    return 0;
}
void dfs(int x,int y,int front)
{
    if (x==n-1 && y==m){
        flag=1;
        for (int i=0;i<top;i++)
            printf("(%d,%d) ",s[i].x,s[i].y);
        return;
    }
    

    if (!isvalid(x,y) || book[x][y]){
       // printf("(%d,%d)",x,y);
        return;
    }

    book[x][y]=1;
    s[top].x=x;
    s[top].y=y;
    top++;

    if (a[x][y]>0 && a[x][y]<=4)
    {
        switch (front)
        {
        case 1:
            dfs(x-1,y,4);
            dfs(x+1,y,2);
            break;
        case 2:
            dfs(x,y-1,3);
            dfs(x,y+1,1);
            break;
        case 3:
            dfs(x-1,y,4);
            dfs(x+1,y,2);
            break;
        case 4:
            dfs(x,y-1,3);
            dfs(x,y+1,1);
            break;
        }
    }
    if (a[x][y]>4 && a[x][y]<=6)
    {
        switch (front)
        {
        case 1:
            dfs(x,y+1,1);
            break;
        case 2:
            dfs(x+1,y,2);
            break;
        case 3:
            dfs(x,y-1,3);
            break;
        case 4:
            dfs(x-1,y,4);
            break;
        }
    }
    book[x][y]=0;
    top--;
}

int main()
{
    int i,j,num=0;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    dfs(0,0,1);
    if (flag)
        printf("找到铺设方案");
    else
        printf("impossible\n");
    return 0;
}
/*5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4*/
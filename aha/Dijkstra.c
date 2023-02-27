#include <stdio.h>
#define INF 99999

int get_u(int* dis,int* book,int n)
{
    int min=INF,u=0;
    for (int i=0;i<n;i++)
    {
        if (!book[i])
        {
            if (dis[i]<min)
            {
                min = dis[i];
                u=i;
            }
        }
    }
    if (u==0)
        return -1;
    return u;
}

int main(void)
{
    int e[10][10],dis[10],book[10]={0};
    int n,m;
    scanf("%d %d",&n,&m);
    book[0]=1;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i==j)  e[i][j]=0;
            else  e[i][j]=INF;
    
    for (int i=0;i<m;i++)
    {
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }

    for (int i=0;i<n;i++)
        dis[i]=e[0][i];

    while(1)
    {
        int u=get_u(dis,book,n);
        if (u==-1){
            break;
        }
        book[u]=1;
        for (int i=0;i<n;i++)
        {
            if (dis[i] > e[u][i]+dis[u])
                dis[i] = e[u][i]+dis[u];
        }
    }
    for (int i=0;i<n;i++)
        printf("%d ",dis[i]);
    return 0;
}
/*
6 9
0 1 1
0 2 11
1 2 9
1 3 3
2 4 5
3 2 4
3 4 13
3 5 15
4 5 4*/
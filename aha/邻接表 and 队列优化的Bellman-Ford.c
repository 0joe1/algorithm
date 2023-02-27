#include <stdio.h>
#include <stdlib.h>
#define INF 99999

struct queue{
    int data[100];
    int head;
    int tail;
};

int u[10],v[10],w[10];
void transfer(int e[10][10],int n,int* first,int* next)
{
    int index=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (e[i][j] && e[i][j]!=INF)
            {
                u[index] = i;
                v[index] = j;
                w[index] = e[i][j];
            
                next[index] = first[i]; 
                first[i] = index;
                index++;
            }
        }
    }
}

int main(void)
{
    int dis[10],e[10][10];
    int n,m;

    scanf("%d %d",&n,&m);
    int* first = (int*)malloc(sizeof(int)*n);
    int* next = (int*)malloc(sizeof(int)*(m));
    for (int i=0;i<n;i++)
        first[i] = -1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if(i==j)  e[i][j]=0;
            else  e[i][j]=INF;

    for (int i=0;i<m;i++)    
    {
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
    transfer(e,n,first,next);

    for (int i=0;i<n;i++)
        dis[i] = INF;
    dis[0]=0;


    int book[10]={0};
    struct queue q;
    q.head=q.tail=0;
    q.data[q.tail++] = 0; book[0]=1;
    while (q.head < q.tail)
    {
        int cur = q.data[q.head];
        int index=first[cur];
        while (index != -1)
        {
            if (dis[v[index]] > dis[u[index]]+w[index])
            {
                dis[v[index]] = dis[u[index]]+w[index];
                if (!book[v[index]])
                {
                    q.data[q.tail++] = v[index];
                    book[v[index]] = 1;
                }
            }
            index = next[index];
        }
        book[cur]=0;
        q.head++;
    }


    
    for (int i=0;i<n;i++)
        printf("%d ",dis[i]);
    return 0;
}
/*
5 5
1 2 2
0 1 -3
0 4 5
3 4 2
2 3 3*/
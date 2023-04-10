#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** gengraph(int n,int m,int* ReturnColsize)
{
    int** ret = (int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++)
    {
        ret[i]=(int*)malloc(sizeof(int)*n);
        ReturnColsize[i]=0;
    }
    for (int i=0;i<m;i++)
    {
        int from,to;
        scanf("%d %d",&from,&to);
        ret[from][ReturnColsize[from]++]=to;
        ret[to][ReturnColsize[to]++]=from; //无向边
    }
    return ret;
}
int n,m;
int flag[10],ind,num[10],low[10];

int min(int a,int b){
    return a<b?a:b;
}
/*
void output_nmgraph(int n,int** nmgraph,int *returnColsize)
{
    for (int i=0;i<n;i++)
    {
        printf("%d:",i);
        for (int j=0;j<returnColsize[i];j++)    
            printf("%d ",nmgraph[i][j]);
        printf("\n");
    }
}*/
void dfs(int fa,int cur,int** graph,int*colSize)
{
    num[cur]=low[cur]=ind;
    ind++;
    for (int i=0;i<colSize[cur];i++)
    {
        int next=graph[cur][i];
        if (num[next] == -1)
        {
            dfs(cur,next,graph,colSize);
            low[cur]=min(low[cur],low[next]);
            if (low[next] > num[cur])
                printf("%d-%d ",cur,next);
        }
        else if (next != fa)
            low[cur]=min(low[cur],num[next]);
    }
    return;
}

int main(void)
{
    scanf("%d %d",&n,&m);
    memset(num,-1,sizeof(int)*n);
    int *colSize = (int*)malloc(sizeof(int)*n);
    int** graph = gengraph(n,m,colSize);
    //output_nmgraph(n,graph,colSize);

    dfs(-1,0,graph,colSize);

    return 0;
}
/*
6 6
0 3
0 2
3 1
2 1
1 4
4 5
*/

#include <stdio.h>
#define INF 99999

int main(void)
{
    int e[10][10],n,m;
    scanf("%d %d",&n,&m);

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i==j) e[i][j]=0;
            else e[i][j]=INF;

    for (int i=0;i<m;i++)
    {
        int t1,t2,t3;
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }

    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                if (e[i][j] > e[i][k]+e[k][j])
                    e[i][j] = e[i][k]+e[k][j];
            }
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            printf("%10d",e[i][j]);
        printf("\n");
    }
     
    return 0;
}
/*
4 8
0 1 2
0 2 6
0 3 4
1 2 3
2 0 7
2 3 1
3 0 5
3 2 12*/
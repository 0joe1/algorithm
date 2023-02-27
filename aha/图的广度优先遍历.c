#include <stdio.h>

typedef struct{
    int data[300];
    int head;
    int tail;
}queue;

int main(void)
{
    int n,m;
    int book[100]={0},e[100][100];
    queue q;
    scanf("%d %d",&n,&m);

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i==j) e[i][j]=0;
            else e[i][j]=999;
    for (int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[a][b]=1;
    }
    q.head = q.tail = 0;
    q.data[q.tail++] = 0;
    book[0]=1;

    while (q.head < q.tail)
    {
        int a=q.data[q.head++];
        
        for (int i=0;i<n;i++)
        {
            if (e[a][i] == 1 && !book[i])
            {
                q.data[q.tail++] = i;
                book[a] = 1;
            }
        }
    }
    for (int i=0;i<q.tail;i++)
        printf("%d ",q.data[i]);
    return 0;
}
/*
5 4
0 1
0 2
0 4
1 3
*/
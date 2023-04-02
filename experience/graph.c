#include <stdio.h>
#include <stdlib.h>

/****************************************A*************************************/
int** Adjacency_Matrix(int n,int** input,int m)
{
    //声明一个数组
    int** ret = (int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++)
        ret[i]=(int*)malloc(sizeof(int)*n);
    //每个元素全部初始化为0
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            ret[i][j]=0;
    //数组元素赋值 
    for (int i=0;i<m;i++)
    {
        int from=input[i][0],to=input[i][1];
        ret[from][to]=1;
    }

    return ret;
}
int find_next(int** Adjacency_Matrix,int n,int p)
{
    int found=0;
    for (int i=0;i<n;i++)
        if (Adjacency_Matrix[p][i])
        {
            printf("%d ",i);
            found=1;
        }
    return found;
}
void output(int n,int **Adjacency_Matrix)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            printf("%d ",Adjacency_Matrix[i][j]);
        printf("\n");
    }
}    
/********************************B*****************************************/
int** nmgraph(int n,int m,int** input,int* returnColsize )
{
    int** ret=(int**)malloc(sizeof(int*)*n);
    
    for (int i=0;i<n;i++) 
    {
        ret[i]=(int*)malloc(sizeof(int)*n);
        returnColsize[i]=0;
    }
    for (int i=0;i<m;i++)
    {
        int from=input[i][0],to=input[i][1];
        ret[from][returnColsize[to]++]=to;
    }

    return ret;
}
void output_nmgraph(int n,int** nmgraph,int *returnColsize)
{
    for (int i=0;i<n;i++)
    {
        printf("%d:",i);
        for (int j=0;j<returnColsize[i];j++)    
            printf("%d ",nmgraph[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int n,m;
    n=4;m=2;
    
    // make input
    int** input=(int**)malloc(sizeof(int*)*m);
    for (int i=0;i<m;i++)
        input[i]=(int*)malloc(sizeof(int)*2);
    for (int i=0;i<m;i++)
        scanf("%d %d",&input[i][0],&input[i][1]);

    /*plan A
    int ** adj;
    adj=Adjacency_Matrix(n,input,m);
    find_next(adj,n,1);
    */

    //plan B
    int* returnColsize=(int*)malloc(sizeof(int)*n);
    int** graph=nmgraph(n,m,input,returnColsize);
    output_nmgraph(n,graph,returnColsize);

    return 0;
}

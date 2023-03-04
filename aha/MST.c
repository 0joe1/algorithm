#include <stdio.h>
/*
 并查集
 从小到大的边使用find测试是否连通
 若是同一个头领，就是连通的，舍弃掉这条边
 反之若不是，就不是连通的，于是merge两个端点
 边数足够（到n-1）后就跳出循环
 */
int n,m;
int uset[10];
struct edge{
    int u;
    int v;
    int w;
};
struct edge e[11];
void quicksort(int left,int right)
{
    int i,j;
    struct edge t;
    if (left >right)
        return;
    i=left;
    j=right;
    while (i!=j)
    {
        while(e[j].w>=e[left].w && i<j)
            j--;
        while(e[i].w<=e[left].w && i<j)
            i++;
        if (i<j)
        {
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    t=e[left];
    e[left]=e[i];
    e[i]=t;

    quicksort(left,i-1);
    quicksort(i+1,right);
}
void uset_init(int n)
{
    for (int i=0;i<n;i++)
        uset[i]=i;
}
int find(int x)
{
    if (x == uset[x]){
        return x;
    }
    uset[x]=find(uset[x]);
    return uset[x];
}
void merge(int x,int y)
{
    int rx=find(x),ry=find(y);
    if (rx == ry){
       return;
    }
    //上面这块好像这次用不上，因为是否同个祖先已经知道了，只merge不同祖先的
    uset[rx]=ry;
}
int main(void)
{
    int cost=0,counter=0;
    scanf("%d %d",&n,&m);
    uset_init(n);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
    quicksort(0,m-1);
    for (int i=0;i<m;i++)
    {
        int rx=find(e[i].u),ry=find(e[i].v);
        if (rx != ry)
        {
            counter++;
            merge(e[i].u,e[i].v);
            cost += e[i].w;
        }

        if (counter==n-1)
            break;
    }
    printf("%d",cost);
    return 0;
}
/*
6 9
1 3 11
2 4 13
3 5 3
4 5 4
1 2 6
3 4 7
0 1 1
2 3 9
0 2 2
*/

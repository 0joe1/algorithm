/*最终目标  连通且总花费最少
 *
 * 连通：如果不能连通，说明那个节点不能和现有的树连接，而要全连通这个点一定是树的一部分
 * 总花费最少：每个点都是花费最少的，加起来肯定最少
 * Q1:
 * 每次新加的点能否不是树本次更新后中最小的（只满足更新后比原来小）？
 * 不能，因为有可能从其他边迂回更小，这样就无法满足“每次添加都花费最少”了。
 * Q2:
 * 一定是从刚添加的节点吗获取新节点吗？
 * 不一定，比如老节点对某个节点的花费仅大于刚添加的节点，而刚添加的节点到所有其他节点的花费都大于那个花费
 *
 * Q3:
 * 一个dis数组储存到其他所有点的最短距离，这个数组使比原来增加了什么优势？
 * 可以帮忙找到最小点，能保证以目前的步数现在目前所有点都是最小的，不能保证现在的所有点以    后都一定是最小的。
 * 以后的其他点比原来的更小的原理是：通过现在的更小点再次以小花费到达。
 * 现在的最小点没有更小点，所有以后也不会变得更小。
 * 
 * 
 */
#include <stdio.h>
#define INF 999999
#define leftchild(a) (2*a+1)
#define rightchild(a) (2*a+2)
#define father(a) ((a-1)/2)

int dis[10],book[10]={0};
int h[10],pos[10],size;
int gtnu(int dis[],int book[],int n)
{
    int min=INF;
    int nu;
    for (int i=0;i<n;i++)
    {
        if (book[i])
            continue;
        if (dis[i]<min)
        {
            min=dis[i];
            nu=i;
        }
    }
    return nu;
}
void swap(int x,int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;

    t = pos[h[x]];
    pos[h[x]] = pos[h[y]];
    pos[h[y]] = t; 
}
void siftdown(int x)
{
    /*
     *get lc and rc
     (if out of bound
     stop)
     */
    int lc,rc;
    while (leftchild(x) < size)
    {
        lc = leftchild(x);
        if ((rc=rightchild(x)) >= size) rc=-1;
        // lc,rc choose the smaller
        int m;
        if (rc==-1)  m=lc;
        else
            m=h[dis[lc]]>h[dis[rc]]?lc:rc;
 
        /*
         if smaller
            swap the pos
            x = next x
         else
            finish
         */
        if (dis[h[x]] > h[dis[m]])
        {
            swap(x,m);
            x = m;
        }
        else break;
    }
}
void create(void)
{
    for (int i=0;i<size;i++)    
    {
        h[i]=i;
        pos[i]=i;    
    }
    //not leaf node sift down
    /*
     *    0
     *   1 2
     *  34 56 
     */
    //the number of notleaf node is (size+1)/2-1=(size-1)/2=size/2
    //so [0,size/2)
    for (int k=size/2-1;k>=0;k--)
        siftdown(k);
}
void siftup(int x)
{
    int f=father(x);
    
    while (x > 0)
    {
        if (dis[h[x]] > dis[h[f]])
            break;
        swap(f,x);
        x=f;
        f=father(x);
    }
}

int pop()
{
    int t=h[0];

    h[0]=h[size-1];
    pos[h[0]]=0;
    size--;
    siftdown(0);

    return t;
}

int main(void)
{
    int n,m;
    int u[20],v[20],w[20],first[6],next[20];
    scanf("%d %d",&n,&m);
    size=n;

    for (int i=0;i<n;i++)
        first[i]=-1;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u[i],&v[i],&w[i]);
    }
    for (int i=0;i<m;i++)
    {

    }

    dis[0]=0;
    for(int i=1;i<n;i++)
        dis[i]= INF;
    int e=first[0];
    while (e != -1)
    {
        dis[v[e]] = w[e];
        e = next[e];
    }
    book[0]=1;
    
    create();
    pop();

    int cost=0;
    for (int i=0;i<n-1;i++)
    {
        int nu=pop();
        book[nu]=1;
        cost += dis[nu];

        int e=first[nu];
        while (e != -1)
        {
            if (!book[v[e]] && dis[v[e]]>w[e])
            {  
                dis[v[e]]=w[e];
                siftup(pos[v[e]]);
            }

            e=next[e];
        }
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


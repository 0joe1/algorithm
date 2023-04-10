/*能回到祖先的定义规则：
 * 某个子树能回到祖先或者本身指向祖先
 *
 * 本节点的某个值依赖其指向的节点，就必须先得到其指向的节点的值
 * 所以dfs到最后不依赖其他节点的节点，从最底层开始赋值到高层节点
 *
 * 什么叫经过？
 * 经过的那个节点作为一个子树的根，数据被汇总到本节点之中。
 *
 * 祖先：可以经过，知道答案
 * 父亲节点：不可经过
 * 普通节点：不知道答案，问附近的祖先，问儿子们
 * 没儿子的节点：问祖先
 *ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
 *  下面的内容可信度较低：
    if (num[fa] <= low[cur])
        flags[fa]=1;
    这两行内容既可以放在dfs(cur,i,flags)的后面，也可以放for循环结束后
    原因分析：
    放dfs后面，每次更新low[cur]都会检查一次是否为割点，如果是祖先节点会跳过但是大丈夫，如果能接触到到祖先节点说明肯定不是接点(low[cur]<num[fa])。
    放在for循环后，low[cur]已经被选出了最小值，如果最小值满足条件，那么其他必然也满足条件。

    low[cur]=low[cur]<num[i]?low[cur]:num[i];
   
    不能简单地替换为：low[cur]=low[cur]<low[i]?low[cur]:low[i];


 */
#include <stdio.h>
int n,m,e[9][9];
int num[9],low[9];
int ind;

void dfs(int fa,int cur,int* flags)
{
    int child=0;
    num[cur]=low[cur]=ind;
    ind++;
    for (int i=0;i<n;i++)
    {
        if (e[cur][i])
        {
            if (num[i] == -1)
            {  
                child++;
                dfs(cur,i,flags);                     
                low[cur]=low[cur]<low[i]?low[cur]:low[i];
                if (cur!=0 && low[i]>=num[cur])
                    flags[cur]=1;
                if (cur==0 && child==1)
                    flags[cur]=0;
            }
            
            if (i != fa)
                low[cur]=low[cur]<num[i]?low[cur]:num[i];
        }
    }
}


int main(void)
{
    for (int i=0;i<9;i++)
    {
        num[i]=low[i]=-1;
    }


    int flags[10]={0};
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) 
        for (int j=0;j<n;j++)
            e[i][j]=0;
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        e[x][y]=1;
        e[y][x]=1;
    }
    dfs(-1,0,flags);
    for (int i=0;i<n;i++)
        if (flags[i])
            printf("%d ",i);
    
    return 0;
}
/*
6 7
0 3
0 2
3 1
2 1
1 4
1 5
4 5
*/

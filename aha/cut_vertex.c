/*能回到祖先的定义规则：
 * 某个子树能回到祖先或者本身指向祖先
 *
 * 本节点的某个值依赖其指向的节点，就必须先得到其指向的节点的值
 * 所以dfs到最后不依赖其他节点的节点，从最底层开始赋值到高层节点
 */
#include <stdio.h>
int n,m,e[9][9],index;
int num[9],low[9];

void dfs(int fa,int cur,int* flags)
{
    num[cur]=low[cur]=index;
    index++;
    for (int i=0;i<n;i++)
    {
        if (e[cur][i])
        {
            if (num[i] != -1)
                dfs(cur,i,flags);
            //low[cur]=low[cur]<low[i]?low[cur]:low[i];
            
            low[]

        }
    }
}


int main(void)
{
    int flag[10];
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

    
    return 0;
}

#include <stdio.h>
int f[1000],n,m;

void init()
{
    for (int i=0;i<n;i++)
        f[i]=i;
}
int find(int x)
{
    if (f[x] == x){
        return x;
    }
    f[x] = find(f[x]);
    return f[x];
}
void merge(int x,int y)
{
    int rx=find(x),ry=find(y);
    if (rx == ry){
        return;
    }
    f[rx]=ry;
}
int main(void)
{
    int x,y;
    scanf("%d %d",&n,&m);

    init();
    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        merge(x,y);
    }
    int ans=0;
    for (int i=0;i<n;i++)
        if (i==f[i])
            ans++;
    printf("%d",ans);
    return 0;
}
    

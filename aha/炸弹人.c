#include <stdio.h>

struct pos{
    int x;
    int y;
};

char a[20][21];
int n,m,book[20][20];
int getnum(int i,int j)
{
    int sum,x,y;
    sum=0;
    x=i;y=j;
    while (a[x][y] != '#')
    {
        if (a[x][y] == 'G')
            sum++;
        x--;
    }
    x=i;y=j;
    while (a[x][y] != '#')
    {
        if (a[x][y] == 'G')
            sum++;
        x++;
    }
    x=i;y=j;
    while (a[x][y] != '#')
    {
        if (a[x][y] == 'G')
            sum++;
        y--;
    }
    x=i;y=j;
    while (a[x][y] != '#')
    {
        if (a[x][y] == 'G')
            sum++;
        y++;
    }
    return sum;
}

_Bool isvalid(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m){
        return 0;
    }
    else if (a[x][y] != '.'){
        return 0;
    }
    return 1;
}

int main(void)
{
    struct pos queue[401];
    int head,tail;
    int startx,starty,mx,my;
    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    head = tail =0;
    queue[tail].x=startx;
    queue[tail].y=starty;
    tail++;
    book[startx][starty]=1;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            scanf("%c",&a[i][j]);
        getchar();
    }

    int next[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


    int max = 0;
    while (head < tail)
    {
        int t = getnum(queue[head].x,queue[head].y);
        if (t>max)
        {
            max = t;
            mx = queue[head].x;
            my = queue[head].y;
        }
        
        int dx,dy;
        for (int i=0;i<4;i++)
        {
            dx=queue[head].x + next[i][0];
            dy=queue[head].y + next[i][1];

            if (isvalid(dx,dy) && !book[dx][dy])
            {
                book[dx][dy]=1;
                queue[tail].x = dx;
                queue[tail].y = dy;
                tail++;
            }
        }
        head++;
    }
    
    printf("(%d,%d),max=%d",mx,my,max);
    return 0;
}
/*
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############*/
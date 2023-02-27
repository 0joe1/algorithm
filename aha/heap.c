#include <stdio.h>
#define root 0
#define lchild(a) (a*2+1)
#define rchild(a) (a*2+2)
#define father(a) ((a-1)/2)
int a[101];
int n;

void swap(int x,int y)
{
    int t;
    t=a[x];
    a[x]=a[y];
    a[y]=t;
}
 
void shiftdown(int i)
{
    int lc,rc;
    lc=rc=0;
	int min=999;
	while (i*2 < n)
	{
		int pos;
		if (lchild(i) < n) lc=lchild(i);
		if (rchild(i) < n) rc=rchild(i);
		if (rc<lc || a[lc] <a[rc])
		{
			min = a[lc];
			pos = lc;
		}
		else
		{
			min = a[rc];
			pos = rc;
		}
			
		if (min < a[i])
		{
			a[pos]=a[i];
			a[i]=min;
			i = pos;
		}
		else
			break;
	}
}
void creat()
{
    for (int i = n/2-1;i>=0;i--)
        shiftdown(i);
}


void shiftup(int i)
{
    while (i!=root)
    {
        if (a[i]<a[father(i)])
        {
            swap(i,father(i));
            i = father(i);
        }
        else
            break;
    }
}
			
int deletemin()
{
    int t;
    t=a[root];
    a[root]=a[n-1];
    n--;
    shiftdown(root);
    return t;
}

int main(void)
{
    scanf("%d",&n);
    int num = n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    creat();
    revheap();

    n=num;
    for(int i=0;i<num;i++)
        printf("%d ",deletemin());
	return 0;
 
}

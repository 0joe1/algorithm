#include <stdio.h>

#define root 0
#define lchild(a) (a*2+1)
#define rchild(a) (a*2+2)
#define father(a) ((a-1)/2)

void shiftdown(int i)
{
	while (i*2 <= N)
	{
		int min=999;
		int pos;
		if (lchild(i) <= N) lc=lchild(i);
		if (rchild(i) <= N) rc=rchild(i);
		if (a[lc] <a[rc])
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
void siftup(int i)
{

			


	




int main(void)
{
	return 0;
}

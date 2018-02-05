//Chef and circle run
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[1000000];
int clock=0;
int anticlock=0,temp;
int main()
{
	int t,n;
	scanf("%d",&t);
	int i,j,u,v;
	for(i=0;i<t;i++)
	{
		clock=0;
		anticlock=0;
		a[0]=0;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		scanf("%d",&a[j]);
		scanf("%d%d",&u,&v);
		for(j=u-1;j<v;j++)
		{
			clock+=a[j];
		}
		j=u-1;
		while(j!=v)
		{
			if(j!=-1)
			{
				anticlock+=a[j];
			    j--;
			}
			else
			{
				j=n;
			}
		}
		anticlock+=a[v];
		if(anticlock<clock)
		temp=anticlock;
		else
		temp=clock;
		printf("%d\n",temp);
	}
	return  0;
}

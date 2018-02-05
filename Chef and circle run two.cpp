//Chef and circle run
#include<stdio.h>
long long int posmin(long long int *,long long int);
long long int a[1000000];
long long int clock=0,tclock=0,tanticlock=0;
long long int anticlock=0,pmin,min;
long long int reclock=0,reanticlock=0;
int main()
{
	long long int t,n,c_count=0,a_count=0;
	scanf("%lld",&t);
	long long int i,j,u,v;
	for(i=0;i<t;i++)
	{
		tclock=0;
		tanticlock=0;
		reclock=0;
		reanticlock=0;
		clock=0;
		anticlock=0;
		a[0]=0;
		scanf("%lld",&n);
		for(j=1;j<=n;j++)
		scanf("%lld",&a[j]);
		scanf("%lld%lld",&u,&v);
		c_count=v-u;
		a_count=u+n-v;
		pmin=posmin(a,n);
		j=u;
		if(c_count>a_count&&(pmin>=u&&pmin<v))
		{
			while(j<=pmin||(tclock+a[j])<tclock)
			{
				tclock+=a[j];
				j++;
			}
			tclock=tclock*2;
		}
		else if(a_count>=c_count&&(pmin>=v||pmin<u))
		{
			j=u-1;
			while(j!=pmin&&(tanticlock+a[j])<tanticlock)
			{
				if(j!=-1)
				{
					tanticlock+=a[j];
				    j--;
				}
				else
				{
					j=n;
				}
			}
			tanticlock+=a[j];
			tanticlock=tanticlock*2;
		}
		for(j=u;j<v;j++)
		{
			clock+=a[j];
		}
		reclock=clock;
		clock+=tanticlock;
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
		reanticlock=anticlock;
		anticlock+=tclock;
	    min=reclock;
	    if(min>clock)
	    min=clock;
	    if(min>anticlock)
	    min=anticlock;
	    if(min>reanticlock)
	    min=reanticlock;
		printf("%lld\n",min);
	}
	return  0;
}
long long int posmin(long long int *b,long long int size)
{
	long long int i,pos=1;
	long long int min=b[1];
	for(i=1;i<=size;i++)
	{
		if(min>b[i])
		{
			min=b[i];
			pos=i;
		}
	}
	return pos;
}

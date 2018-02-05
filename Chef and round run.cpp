//Chef and round run
#include<stdio.h>
long long int a[1000000];
int temp[1000000]={0};
int main()
{
	long long int t,count;
	scanf("%lld",&t);
	long long int i,n,j,x,k;
	for(i=0;i<t;i++)
	{
		count=0;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		for(j=0;j<n;j++)
		temp[j]=0;
        for(j=0;j<n;j++)
		{
			x=j;
			while(temp[x]==0)
			{
				temp[x]=1;
				x=(x+a[x]+1)%n;
			}
			k=j;
			if(x==j&&temp[x]!=-1)
			count++;
			else
			{
				while(k!=x)
				{
					temp[k]=-1;
					k=(k+a[k]+1)%n;
				}
			}
	    }   	
		printf("%lld\n",count);
	}
	return 0;
}

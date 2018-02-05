#include<stdio.h>
int main()
{
	long int t;
	int a[100000];
	scanf("%ld",&t);
	while(t!=-1)
	{
	long long int sum=0;
	int i;
	for(i=0;i<t;i++)
	{
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	long int count=0;
	if(sum%t>0)
	{
		printf("-1\n");
	}
	else
	{
		long int avg=sum/t;
		for(i=0;i<t;i++)
		{
			if(avg>a[i])
			{
				count=count+avg-a[i];
			}
		}
		printf("%ld\n",count);
	}
			scanf("%ld",&t);
	}
	return 0;
}

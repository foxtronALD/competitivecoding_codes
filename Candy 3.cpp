#include<stdio.h>
long long int a[10000000];
int main()
{
	long long int t,i,sum[100000]={0};
	scanf("%lld",&t);
	printf("\n");
	long long int n[100000];
	long long int j;
	for(i=0;i<t;i++)
	{
		sum[i]=0;
		scanf("%lld",&n[i]);
		for(j=0;j<n[i];j++)
		{
			scanf("%lld",&a[j]);
			sum[i]=sum[i]+a[j];
		}
		printf("\n");
	}
	for(i=0;i<t;i++)
	{
		if(sum[i]%n[i]==0)
		printf("Yes");
		else printf("No");
		printf("\n");
	}
	
	return 0;
}

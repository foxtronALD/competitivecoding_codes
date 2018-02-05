#include<stdio.h>
int main()
{
	long long int t,n,temp,sum=0;
	scanf("%lld",&t);
	long long int j;
	while(t--)
	{
		sum=0;
		printf("\n");
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&temp);
			sum=(sum+temp)%n;
		}
		if(sum%n==0)
		{
			printf("YES\n");
		}
		else
		printf("NO\n");
	}
	return 0;
}

#include<stdio.h>
int main()
{
	long long int t;
	long long int sum=0;
	scanf("%lld",&t);
	long long int i,n;
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		sum=(n*(3*n+1)/2)%1000007;
		printf("%lld\n",sum);
	}
	return 0;
}

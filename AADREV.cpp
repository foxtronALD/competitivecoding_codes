#include<stdio.h>
long long int reverse(long long int);
long long int sum,temp;
int main()
{
	long long int n,i;
	long long int a,b;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		temp=0;
		scanf("%lld%lld",&a,&b);
		temp=reverse(reverse(a)+reverse(b));
		printf("%lld\n",temp);
	}
	return 0;
}
long long int reverse(long long int x)
{
	sum=0;
	while(x!=0)
	{
		sum=sum*10+x%10;
		x/=10;
	}
	return sum;
}

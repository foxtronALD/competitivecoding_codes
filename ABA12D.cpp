//Here i will use the concept of sieves and the logic
#include<bits/stdc++.h>
using namespace std;
int sum(int);
int prime[1000002];
int number[40];
int main()
{
    int i,t,j,a,b,k,cou=0;
    int temp;
    for(i=2;i*i<=1000000;i++)
    {
        if(prime[i]==0)
        {
            for(j=i;j*i<=1000000;j++)
            {
                if(prime[i*j]==0)
                prime[i*j]=i;//Implementing sieve
            }
        }
    }
    number[0]=2;
    k=1;
    for(i=2;i*i<=1000000;i++)
        {
            temp=i;
            {
                if(prime[i]==0)
                {
                    if(prime[sum(i*i)]==0)
                            number[k++]=i*i;
                }
                else
                {
                    while(temp%prime[i]==0)
                    {
                        temp=temp/prime[i];
                    }
                    if(temp==1)
                    {
                        if(prime[sum(i*i)]==0)
                            number[k++]=i*i;
                    }
                }
            }
        }
    scanf("%d",&t);
    while(t--)
    {
        cou=0;
        scanf("%d%d",&a,&b);
        for(i=0;i<=38;i++)
            if(number[i]>=a&&number[i]<=b)
        {
            cou++;
        }
        printf("%d\n",cou);
    }
    return 0;
}
int sum(int x)
{
	int sumd=0;
	int i;
	for(i=1;i*i<=x;i++)
	{
		if(x%i==0&&x/i!=i)
		sumd=sumd+x/i+i;
		else if(x%i==0)
		sumd=sumd+i;
	}
	return sumd;
}

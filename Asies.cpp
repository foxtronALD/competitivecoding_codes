//Spoj problem
#include<stdio.h>
int prime[1000002]={0};
int etf[1000002]={0};
int main()
{
    int t;
    int i,n,j;
    scanf("%d",&t);
    for(i=2;i<=1000000;i++)
    {
        if(prime[i]==0)
        {
            etf[i]=i-1;
            for(j=2;j*i<=1000000;j++)
            {
               prime[i*j]=1;
               if(etf[i*j]==0)
                    etf[i*j]=i*j;
               etf[i*j]=(etf[i*j]/i)*(i-1);
            }
        }
    }
    etf[1]=1;
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",etf[n]);
    }
    return 0;
}

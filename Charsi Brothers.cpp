#include<bits/stdc++.h>
using namespace std;
int a[1000002];
long long t[1000002];
//long long ans[1000002];
long long te[1000002];
long long prime[100002];
int main()
{
    long long int i,j,n,k,temp1,temp2;
    int num=0;
    long long coun;
    long long sum=0;
    double p;
    long long int l,u;
    scanf("%lld%lld%lf",&l,&u,&p);
    for(i=2;i*i<=1000001;i++)
    {
        if(a[i]==0)
        for(j=i;j*i<=1000001;j++)
        {
            a[i*j]=i;
        }
    }

    k=0;

    for(i=2;i<=1000001;i++)
        if(a[i]==0)
        prime[k++]=i;

    for(i=l;i<=u;i++)
        te[i-l]=i;

    for(j=0;j<k;j++)
    {
        if(l>prime[j])
            temp1=l/prime[j];
        else
            temp1=2;
        for(i=temp1;i*prime[j]<=u;i++)
        {
            if(l<=i*prime[j])
            {
                coun=0;
                temp2=te[i*prime[j]-l];
                while((temp2%prime[j])==0)
                {
                    coun++;
                    temp2=temp2/prime[j];
                    te[i*prime[j]-l]=temp2;
                }
                t[i*prime[j]-l]+=coun;
            }
        }
    }
    for(i=l;i<=u;i++)
    {
        coun=0;
        if(t[i-l]!=0)
        {
            num++;
            sum+=t[i-l];
            if(te[i-l]!=1)
                sum++;
        }
    }
    double ans=((double)sum/num)*(1-p)+p;
    printf("%lf",ans);
    //printf("sum : %d\n",sum);
    //printf("non - primes : %d\n",num);
    return 0;
}

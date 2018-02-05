#include<bits/stdc++.h>
using namespace std;
long long int a[1000002];
long long int sum[1000002];
int bar[1000002];
long long int mini[1000002];
int main()
{
    int i,t,n;
    long long int maxi;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sum[0]=a[0];
        bar[0]=1;
        mini[0]=a[0];
        for(i=1;i<n;i++)
        {
            if(min(mini[i-1],a[i])*(bar[i-1]+1)>a[i])
            {
                sum[i]=min(mini[i-1],a[i])*(bar[i-1]+1);
                mini[i]=min(mini[i-1],a[i]);
                bar[i]=bar[i-1]+1;
            }
            else if(min(mini[i-1],a[i])*(bar[i-1]+1)<a[i])
            {
                bar[i]=1;
                sum[i]=a[i];
                mini[i]=a[i];
            }
            else
            {
                mini[i]=a[i];
                sum[i]=a[i];
                bar[i]=bar[i-1]+1;
            }
        }
        maxi=LONG_MIN;
        for(i=0;i<n;i++)
        {
            if(maxi<sum[i])
                maxi=sum[i];
        }
        /*for(i=0;i<n;i++)
            printf("%d ",sum[i]);
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",bar[i]);*/
        printf("%lld\n",maxi);
    }
    return 0;
}

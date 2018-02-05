#include<bits/stdc++.h>
using namespace std;
int a[600][600];
long long dp[600][600];
int main()
{
    int t,n,m,i,j;
    long long p,q,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0&&j==0)
                    dp[i][j]=0;
                else
                {
                    if(i>0)
                        p=dp[i-1][j];
                    else
                        p=INT_MIN;
                    if(j>0)
                        q=dp[i][j-1];
                    else
                        q=INT_MIN;
                    ans=max(p,q);
                    if(a[i][j]<0)
                        dp[i][j]=a[i][j]+ans;
                    else
                        dp[i][j]=ans;
                }
            }
        }
        if(dp[n-1][m-1]<=0)
            printf("%lld\n",abs(dp[n-1][m-1])+1);
        else
            printf("1\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }
    }
    return 0;
}

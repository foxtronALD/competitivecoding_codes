#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int dp[1000002];
int main()
{
    int t,n,i,j,coun;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            j=i+1;
            coun=0;
            while(a[i]<=a[j]&&j<n)
            {
                j++;
                coun++;
            }
            dp[i]=coun+1;
            if(a[i]<=a[i-1])
                dp[i]+=dp[i-1];
        }
        int maxi=INT_MIN;
        for(i=0;i<n;i++)
            if(maxi<dp[i]*a[i])
            maxi=dp[i]*a[i];
        for(i=0;i<n;i++)
            printf("%d ",dp[i]);
        printf("%d\n",maxi);
    }
    return 0;
}

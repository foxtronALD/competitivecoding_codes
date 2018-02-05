#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int a[1002];
int b[20026];
long long dp[1002][2025];
int n;
long long func(int index,int val)
{
    //printf("index : %d ",index);
    if(index==n+1)
    {
        if(b[val]!=0)
            return 0;
        else
            return 1;
    }
    if(dp[index][val]!=-1)
        return dp[index][val];
    long long ans=0;
    ans=(func(index+1,val))%mod;
    ans=(ans+(func(index+1,(val^a[index])))%mod)%mod;
    return dp[index][val]=ans;
}
int main()
{
    int t,m,x,i,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&x);
            b[x]++;
        }
        //b[0]=1;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",j,func(1,0));
        memset(b,0,sizeof(b));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
char a[10001];
long int cum[10001];
long long int dp[1001][1001];
int n;
long long int func(int index,long int bal)
{
    if(index==n)
        return (bal==0);
    if(dp[index][bal]!=-1)
        return dp[index][bal];
    long long int ans=0;
    if(a[index]=='(')
    {
        ans+=((func(index+1,bal+1))%mod+(func(index+1,bal)%mod))%mod;
    }
    else
    {
        if(bal>0)
            ans=(ans%mod+func(index+1,bal-1)%mod)%mod;
        if(cum[index-1]-bal>0)
            ans=(ans%mod+func(index+1,bal)%mod)%mod;
    }
    return dp[index][bal]=ans;
}
int main()
{
    int t,i;
    scanf("%d%*c",&t);
    while(t--)
    {
        scanf("%s",a);
        n=strlen(a);
        memset(cum,0,sizeof(cum));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            if(a[i]=='(')
            {
                if(i>0)
                cum[i]=cum[i-1]+1;
                else
                    cum[i]=1;
            }
            else
            {
                cum[i]=cum[i-1]-1;
            }
        }
        printf("%lld\n",func(0,0));
    }
    return 0;
}

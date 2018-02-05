#include<bits/stdc++.h>
using namespace std;
long long dp[20][1048577];
int n;
vector <int> v1[20];
long long func(int index,int mask)
{
    int x;
    if(index==n)
    {
        if(mask==((1<<n)-1))
        {
            return 1;
        }
        else
            return 0;
    }
    if(mask==((1<<n)-1))
    {
        return 0;
    }
    if(dp[index][mask]!=-1)
        return dp[index][mask];
    long long ans=0;
    for(int i=0;i<v1[index].size();i++)
    {
        x=1<<v1[index][i];
        if((x&mask)==0)
        {
            ans=ans+func(index+1,mask|(x));
        }
    }
    return dp[index][mask]=ans;
}
int main()
{
    int t,i,j,x;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&x);
                if(x==1)
                    v1[i].push_back(j);
            }
        }
        printf("%lld\n",func(0,0));
        memset(v1,0,sizeof(v1));
    }
    return 0;
}

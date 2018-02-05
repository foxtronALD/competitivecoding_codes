#include<bits/stdc++.h>
using namespace std;
int a[600][600];
pair<long long,long long> dp[600][600];
int n,m;
pair<long long,long long> func(int x,int y)
{
    if(x<0||y<0)
        return make_pair(INT_MIN+10000,INT_MIN+10000);
    if(x==0&&y==0)
        return dp[x][y]=a[x][y];
    if(dp[x][y].first!=0)
        return dp[x][y];
    pair<long long,long long> ans,p,q;
    p=func(x-1,y);
    q=func(x,y-1);
    ans.second=max( min(a[x][y]+p.first,p.second),min(a[x][y]+q.first,q.second) );
    if(ans.second==min(a[x][y]+p.first,p.second))
    {
        ans.first=a[x][y]+p.first;
    }
    else
    {
        ans.first=a[x][y]+q.first;
    }
    if((ans.second==min(a[x][y]+p.first,p.second))&&(ans.second==min(a[x][y]+q.first,q.second)))
    {
        ans.first=a[x][y]+max(p.first,q.first);
    }
    return dp[x][y]=ans;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        }
        memset(dp,0,sizeof(dp));
        pair<long long,long long> res=func(n-1,m-1);
        if(res.second<=0)
            printf("%lld\n",abs(res.second)+1);
        else
            printf("%lld\n",res.second);
    }
    return 0;
}

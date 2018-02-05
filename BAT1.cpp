#include<bits/stdc++.h>
using namespace std;
int cost[100][100];
int rating[100][100];
int base[100];
int dp[21][21][1000][2];
//int n,m,k;
int func(int x,int y,int cap,int flag,int n,int m)
{
    if(x==n+1||y==m+1||cap==0)
        return 0;
    if(dp[x][y][cap][flag]!=-1)
        return dp[x][y][cap][flag];
    int ans=0;
    ans=max(ans,func(x,y+1,cap,flag,n,m));
    ans=max(ans,func(x+1,y,cap,0,n,m));
    if((flag==0)&&(cap>=cost[x][y]+base[x]))
    {
        ans=max(ans,rating[x][y]+func(x,y+1,cap-cost[x][y]-base[x],1,n,m));
        ans=max(ans,rating[x][y]+func(x,y,cap-cost[x][y]-base[x],1,n,m));
        ans=max(ans,rating[x][y]+func(x+1,y,cap-cost[x][y]-base[x],0,n,m));
    }
    else if((flag==1)&&(cap>=cost[x][y]))
    {
        ans=max(ans,rating[x][y]+func(x,y+1,cap-cost[x][y],flag,n,m));
        ans=max(ans,rating[x][y]+func(x,y,cap-cost[x][y],flag,n,m));
        ans=max(ans,rating[x][y]+func(x+1,y,cap-cost[x][y],0,n,m));
    }
    return dp[x][y][cap][flag]=ans;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&base[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&cost[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&rating[i][j]);
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",func(1,1,k,0,n,m));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1002][1002];
int dp[1002][1002];
int mini[1002][1002];
int n,m;
int t;
int dfs(int x,int y)
{
    if(x<1||y<1||x>n||y>m)
    {
        mini[x][y]=INT_MAX;
        return INT_MIN;
    }
    int p,q,sum;
    if(dp[x][y]!=0)
        return dp[x][y];
    p=dfs(x,y-1);
    q=dfs(x-1,y);
    if(mini[x-1][y]>mini[x][y-1]&&mini[x][y-1]!=INT_MAX)
    {
        if(mini[x-1][y]!=INT_MAX)
        {
            dp[x][y]=sum=a[x][y]+q;
            mini[x][y]=min(sum,mini[x-1][y]);
        }
        else
        {
            dp[x][y]=sum=a[x][y]+p;
            mini[x][y]=min(sum,mini[x][y-1]);
        }
    }
    else if(mini[x-1][y]<mini[x][y-1]&&mini[x-1][y]!=INT_MAX)
    {
        if(mini[x][y-1]!=INT_MAX)
        {
            dp[x][y]=sum=a[x][y]+p;
            mini[x][y]=min(sum,mini[x][y-1]);
        }
        else
        {
            dp[x][y]=sum=a[x][y]+q;
            mini[x][y]=min(sum,mini[x-1][y]);
        }
    }
    else if((p)<(q)&&(mini[x][y-1]!=INT_MAX&&mini[x][y-1]!=INT_MAX))
    {
        dp[x][y]=sum=a[x][y]+q;
        mini[x][y]=min(sum,mini[x-1][y]);
    }
    else if(p>q&&(mini[x][y-1]!=INT_MAX&&mini[x][y-1]!=INT_MAX))
    {
        dp[x][y]=sum=a[x][y]+p;
        mini[x][y]=min(sum,mini[x][y-1]);
    }
    else
    {
        if( !( p==INT_MIN && q==INT_MIN ) )
            dp[x][y]=sum=a[x][y]+p;
        else
            dp[x][y]=sum=a[x][y];
        mini[x][y]=min(sum,mini[x][y-1]);
    }
    return dp[x][y];
}
int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        }
        dfs(n,m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                printf("%d ",mini[i][j]);
            printf("\n");
        }
        if(mini[n][m]<0)
            printf("%d\n",abs(mini[n][m])+1);
        else
            printf("%d\n",1);
        memset(dp,0,sizeof(dp));
        memset(mini,0,sizeof(mini));
    }
    return 0;
}

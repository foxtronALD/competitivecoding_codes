#include<bits/stdc++.h>
using namespace std;
int tii,n,global;
int a[22][22];
pair<int,int> dp[22][22][1026];
//int asd[100][100];
pair<int,int> func(int x,int y,int time)
{
    pair<int,int> temp;
    if(time>=tii&&(x!=n||y!=n))
        return dp[x][y][time]=make_pair(INT_MAX,INT_MAX);
    else if(time>=tii)
        return make_pair(INT_MAX,INT_MAX);
    if(x==n&&y==n)
        return make_pair(a[1][1],time);
    if(dp[x][y][time].first!=-1)
        return dp[x][y][time];
    pair<int,int> ans=make_pair(INT_MAX,INT_MAX);
    if(y+1<=n&&a[x][y+1]>a[x][y])
    {
        pair <int,int> p=func(x,y+1,time+(a[x][y+1]-a[x][y]));
        ans.first=max(a[x][y+1]-a[x][y],p.first);
        ans.second=p.second;
    }
    else if(y+1<=n)
    {
        pair <int,int> p=func(x,y+1,time+(a[x][y]-a[x][y+1]));
        ans.first=p.first;
        ans.second=p.second;
    }
    temp=ans;
    if(x+1<=n&&a[x+1][y]>a[x][y])
    {
        pair<int,int> q=func(x+1,y,time+(a[x+1][y]-a[x][y]));
        ans.first=min( ans.first , max(a[x+1][y]-a[x][y],q.first));
        if(ans.first!=temp.first)
        ans.second=q.second;
        else if(ans.first==temp.first)
            ans.second=min(ans.second,q.second);
    }
    else if(x+1<=n)
    {
        pair<int,int> q=func(x+1,y,time+(a[x][y]-a[x+1][y]));
        ans.first=min(ans.first,q.first);
        if(ans.first!=temp.first)
            ans.second=q.second;
        else if(ans.first==temp.first)
            ans.second=min(ans.second,q.second);
    }
    dp[x][y][time]=ans;
    return ans;
}
/*int cal(int x,int y)
{
    if(x==n&&y==n)
        return 0;
    if(dp[x][y+1]<dp[x+1][y])
        return asd[x][y]=abs(a[x][y+1]-a[x][y])+cal(x,y+1);
    else if(dp[x][y+1]>dp[x+1][y])
        return asd[x][y]=abs(a[x+1][y]-a[x][y])+cal(x+1,y);
    else
    {
        return asd[x][y]=min(abs(a[x][y+1]-a[x][y])+cal(x,y+1),abs(a[x+1][y]-a[x][y])+cal(x+1,y));
    }
}*/
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d%d",&n,&tii);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        }
        global=a[1][1];
        pair <int,int> res=func(1,1,a[1][1]);
        /*for(i=1;i<=n+1;i++)
        {
            dp[i][n+1]=INT_MAX;
            dp[n+1][i]=INT_MAX;
        }*/
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        if(res.first!=INT_MAX)
        {
            //global+=cal(1,1);
            printf("YES : %d %d\n",res.first,tii-res.second);
        }
        else
            printf("NO\n");
        /*
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%d ",asd[i][j]);
            printf("\n");
        }*/
    }
    return 0;
}

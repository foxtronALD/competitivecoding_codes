#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int a[1001];
int n;
int robin;
int lds(int idx,int last,int c)
{
    if(idx==n+1)
        return 0;
    if(dp[idx][last]!=-1)
        return dp[idx][last];
    int ans=lds(idx+1,last,c);
    if(last==0||a[last]>a[idx])
    {
        if(idx==robin)
            ans=max(ans,1+lds(idx+1,idx,1));
        else
            ans=max(ans,1+lds(idx+1,idx,0));
    }
    if(last!=0&&c>0&&a[last]<=a[idx])
        ans=max(ans,1+lds(idx+1,idx,0));
    return dp[idx][last]=ans;
}
int main()
{
    int t,i,j,c=0;
    scanf("%d",&t);
    while(t--)
    {
        c=0;
        scanf("%d%d",&n,&robin);
        robin++;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",lds(1,0,0));
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[102];
int dp[102][102][102];
int n;
int func(int index,int last,int last0)
{
    //printf("index : %d last : %d last0 %d\n",index,last,last0);
    if(index==n+1)
        return 0;
    if(dp[index][last][last0]!=-1)
        return dp[index][last][last0];
    int ans=0;
    ans=max(ans,func(index+1,last,last0));

    if(last==0||a[last]<a[index])
        ans=max(ans,1+func(index+1,index,last0));

    if(last0==0||a[last0]>a[index])
        ans=max(ans,1+func(index+1,last,index));

    if((last==0||a[last]<a[index])&&(last0==0||a[last0]>a[index]))
        ans=max(ans,1+func(index+1,index,index));
    //printf("Res : %d\n",ans);
    return dp[index][last][last0]=ans;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",func(1,0,0));
    }
    return 0;
}

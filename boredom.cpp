#include<bits/stdc++.h>
using namespace std;
int a[100002]={0};
long long int dp[100002]={0};
int n;
int maxi;
long long int func(int x)
{
    int p,q;
    if(x<1||x>maxi)
        return 0;
    if(a[x]==0)
        return func(x+1);
    if(dp[x]!=0)
        return dp[x];
    return dp[x]=max((long long int)x*a[x]+func(x+2),func(x+1));
}
int main()
{
    scanf("%d",&n);
    int i,x;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x]++;
        if(maxi<x)
            maxi=x;
    }
    printf("%lld",func(1));
    return 0;
}

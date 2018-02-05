#include<bits/stdc++.h>
using namespace std;
int n,m;
vector < pair <int,int> > v1(10000);
int dp[52][52];
char a[102][102];
int dfs(int x,int y,int p,int q)
{
    int res=0;
    if(x>n-1||y>m-1||x<0||y<0)
        return 0;
    if(p!=-1&&(a[p][q]!=(char)(a[x][y]-1)))
        return 0;
    if(dp[x][y]!=0)
        return dp[x][y];
        res=max(res,dfs(x-1,y,x,y));
        res=max(res,dfs(x-1,y+1,x,y));
        res=max(res,dfs(x,y+1,x,y));
        res=max(res,dfs(x+1,y+1,x,y));
        res=max(res,dfs(x+1,y,x,y));
        res=max(res,dfs(x+1,y-1,x,y));
        res=max(res,dfs(x,y-1,x,y));
        res=max(res,dfs(x-1,y-1,x,y));
        return dp[x][y]=1+res;
}
int main()
{
    int index=1;
    int i,j;
    scanf("%d%d%*c",&n,&m);
    while(!(n==0&&m==0))
    {
        for(i=0;i<n;i++)
        {
            //for(j=0;j<m;j++)
                scanf("%s",&a[i]);
            scanf("%*c");
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            if(a[i][j]=='A')
            v1.push_back(make_pair(i,j));
        int maxi=0;
        for(i=0;i<v1.size();i++)
        {
            maxi=max(maxi,dfs((v1[i]).first,(v1[i]).second,-1,-1));
        }
        printf("Case %d: %d\n",index,maxi);
        memset(dp,0,sizeof(dp));
        v1.clear();
        scanf("%d%d%*c",&n,&m);
        index++;
    }
    return 0;
}

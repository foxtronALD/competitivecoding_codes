#include<bits/stdc++.h>
using namespace std;
char common[1000];
int dp1[102][102][102];
int dp2[102][102];
int k=0;
int lcs(char *a,char *b,int x,int y,int cap)
{
    if(x<0||y<0||cap==0)
        return 0;
    if(dp1[x][y][cap]!=-1)
        return dp1[x][y][cap];
    dp1[x][y][cap]=max(lcs(a,b,x-1,y,cap),lcs(a,b,x,y-1,cap));
    if(a[x]==b[y]&&cap>0)
        dp1[x][y][cap]=max(dp1[x][y][cap],(int)a[x]+lcs(a,b,x-1,y-1,cap-1));
     return dp1[x][y][cap];
}
int normal(char *a,char *b,int x,int y)
{
    if(x<0||y<0)
        return 0;
    if(dp2[x][y]!=-1)
        return dp2[x][y];
    if(a[x]==b[y])
        return dp2[x][y]=1+normal(a,b,x-1,y-1);
    else
        return dp2[x][y]=max(normal(a,b,x-1,y),normal(a,b,x,y-1));
}
int main()
{
    char a[1000],b[1000];
    int t,n,m,i,j,x,y,c,val;
    scanf("%d%*c",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        memset(common,0,sizeof(common));
        memset(dp2,-1,sizeof(dp2));
        memset(dp1,-1,sizeof(dp1));
        n=strlen(b);
        m=strlen(a);
        val=normal(a,b,m-1,n-1);
        scanf("%d",&c);
        if(val>=c)
            printf("%d\n",lcs(a,b,m-1,n-1,c));
        else
            printf("0\n");
    }
    return 0;
}

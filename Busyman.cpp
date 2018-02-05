#include<bits/stdc++.h>
using namespace std;
int a[1000001]={0};
int b[1000001]={0};
vector < pair <int,int> > v;
multiset <int> ms;
int main()
{
    int t,n,i,x,y,s,flag,rs;
    scanf("%d",&t);
    multiset <int> ::iterator it;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=-1;
            b[y]=max(x+1,b[y]);
        }
        int rs=0;
        flag=0;
        for(i=0;i<=1000000;i++)
        {
            if(b[i]>0)
            {
                rs=max(a[b[i]-1]+1,rs);
            }
            if(a[i]==-1)
            {
                a[i]=rs;
            }
        }
        for(i=0;i<=1000000;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        printf("%d\n",rs);
    }
    return 0;
}

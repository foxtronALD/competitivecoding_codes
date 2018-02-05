#include<bits/stdc++.h>
using namespace std;
int hole[1000002];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i,x,y;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        hole[x]=1;
    }
    int bone=1;
    int ans=0;
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        if(hole[bone]==1&&ans==0)
            ans=bone;
        if(bone==x)
        {
            bone=y;
        }
        else if(bone==y)
        {
            bone=x;
        }
    }
    if(ans!=0)
        printf("%d",ans);
    else
        printf("%d",bone);
    return 0;
}

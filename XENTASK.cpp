#include<bits/stdc++.h>
using namespace std;
int x[100000];
int y[100000];
int main()
{
    int t,n,i,j;
    long long xodd,xeven,yodd,yeven;
    scanf("%d",&t);
    while(t--)
    {
        xodd=yodd=yeven=xeven=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
        }
        for(i=1;i<=n;i++)
            scanf("%d",&y[i]);
        for(i=1;i<=n;i++)
        {
            if(i%2)
            {
                xodd+=x[i];
                yodd+=y[i];
            }
            else
            {
                xeven+=x[i];
                yeven+=y[i];
            }
        }
        printf("%lld\n",min(xodd+yeven,yodd+xeven));
    }
    return 0;
}

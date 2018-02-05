//Simple dp problem
#include<bits/stdc++.h>
using namespace std;
long int a[1000002];
long int b[1000002];
long long int pre1[1000002];
long long int pre2[1000002];
int n,q;
int main()
{
    scanf("%d%d",&n,&q);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        if(i%2)
        {
            pre1[i]=pre1[i-1]+a[i];
            pre2[i]=pre2[i-1]+b[i];
        }
        else
        {
            pre1[i]=pre1[i-1]+b[i];
            pre2[i]=pre2[i-1]+a[i];
        }
    }
    int x,y,z;
    long long int res;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)
        {
            if(y%2)
            {
                res=pre1[z]-pre1[y-1];
            }
            else
                res=pre2[z]-pre2[y-1];
        }
        if(x==2)
        {
            if(y%2)
            {
                res=pre2[z]-pre2[y-1];
            }
            else
                res=pre1[z]-pre1[y-1];
        }
        printf("%lld\n",res);
    }
    return 0;
}

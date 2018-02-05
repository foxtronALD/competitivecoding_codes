#include<bits/stdc++.h>
using namespace std;
long long int a[1000002];
long long int pre[1000002];
int zero(long long int g)
{
    int c=0;
    while(g%10==0)
    {
        g/=10;
        c++;
    }
    return c;
}
int main()
{
    pre[0]=1;
    int t;
    long long int n,m,i,cou;
    long long int s;
    long long int p,q,r;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i==1)
            pre[i]=a[i];
        else
            pre[i]=a[i]*pre[i-1];
    }
    cou=0;
    while(m--)
    {
        scanf("%lld%lld%lld",&p,&q,&r);
        if(p==1||p==2)
        {
            scanf("%lld",&s);
            if(p==1)
            {
                for(i=q;i<=r;i++)
                {
                    a[i]=a[i]*s;
                    pre[i]=pre[i-1]*a[i];
                }
                while(i<=n)
                {
                    pre[i]=pre[i-1]*a[i];
                    i++;
                }
            }
            else if(p==2)
            {
                for(i=q;i<=r;i++)
                {
                    a[i]=s*(i-q+1);
                    pre[i]=pre[i-1]*a[i];
                }
                while(i<=n)
                {
                    pre[i]=pre[i-1]*a[i];
                    i++;
                }
            }
        }
        else if(p==3)
        {
            cou=cou+zero(pre[r]/pre[q-1]);
        }
    }
    printf("%lld\n",cou);
    }
    return 0;
}

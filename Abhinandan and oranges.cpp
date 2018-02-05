#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long fact[2000004];
long long a[1000002];
map <int,int> mp;
long long power(long long a,long long b)
{
    if(b==1)
        return a%mod;
    if(b==0)
        return 1;
    long long p=power(a,b/2);
    if(b%2)
        return ((((p)*(p))%mod)*(a%mod))%mod;
    else
        return ((p)*(p))%mod;
}
int main()
{
    long long t,n,i,j,q;
    long long x,y,z;
    fact[0]=1;
    for(i=1;i<=2000002;i++)
    {
        fact[i]=((i)*(fact[i-1]))%mod;
    }
    //{
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            mp[a[i]]=mp[a[i]]+1;
        }
        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&x);
            if(x==1)
            {
                scanf("%lld%lld",&y,&z);
                mp[a[y-1]]=mp[a[y-1]]-1;
                if(mp[a[y-1]]==0)
                    mp.erase(a[y-1]);
                mp[z]=mp[z]+1;
                a[y-1]=z;
            }
            else
            {
                scanf("%lld",&y);
                long long ans=((fact[y])*(fact[mp.size()-1]))%mod;
                printf("%lld\n",((fact[mp.size() + y - 1])*(power(ans,mod-2)))%mod);
            }
        }
    //}
    return 0;
}

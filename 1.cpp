#include<bits/stdc++.h>
using namespace std;
long long int a[1000005];
int main()
{
    long long int t,n,q,i,j;
    long long int m;
    long long int *p,*r;
    memset(a,-1,sizeof(a));
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&m);
            if(binary_search(a,a+n,m))
            {
                p=lower_bound(a,a+n,m);
                r=upper_bound(a,a+n,m);
                 // if(p<a+n&&r!=a)
                cout<<(p-a)+1<<" "<<(r-a-1)+1<<endl;
            }
            else
                printf("-1\n");
        }
    }
    return 0;
}

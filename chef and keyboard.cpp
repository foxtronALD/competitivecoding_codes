#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,m,p,q,i,c,len,cou;
    scanf("%lld",&t);
    while(t--)
    {
        cou=0;
        scanf("%lld%lld%lld",&n,&m,&c);
        if(n*m<c)
        {
            printf("0\n");
            continue;
        }
        p=min(n,m);
        q=max(n,m);
        len=sqrt(c);
        for(i=1;i<=len;i++)
        {
            if(c%i==0)
            {
                if(i<=p&&(c/i)<=q)
                    cou++;
                if(i<=q&&(c/i)<=p)
                    cou++;
                if(i==c/i)
                    cou--;
            }
        }
        printf("%lld\n",cou);
    }
    return 0;
}

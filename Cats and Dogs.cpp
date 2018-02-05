#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,c,d,l,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&c,&d,&l);
        if(c-2*d<=0)
            n=0;
        else
            n=c-2*d;
        if(l%4==0&&(n+d)*4<=l&&(c+d)*4>=l)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

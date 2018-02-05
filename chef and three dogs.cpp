#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,s,v;
    double time;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&s,&v);
        time=(2.0*s)/(3.0*v);
        time=round(time*10000000)/10000000;
        printf("%.7lf\n",time);
    }
    return 0;
}

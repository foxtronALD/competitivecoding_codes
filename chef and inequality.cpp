#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,a,b,c,d;
    scanf("%lld",&t);
    long long int cou=0;
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        cou=0;
        if(b<c)
        cou=(b-a+1)*(d-c+1);
        else if(a<=c&&b>=d)
        cou=(c-a)*(d-c+1)+(d-c)*(d-c+1)/2;
        else if(a<=c&&b<=d)
            cou=(c-a)*(d-c+1)+(b-c)*(b-c+1)/2+(b-c)*(d-b)+d-b;
        else if(c<=a&&d<=b&&d>=a)
            cou=(d-a)*(d-a+1)/2;
        else if(c<=a&&b<=d)
            cou=(b-a-1)*(b-a)/2+(d-b)+(b-a)*(d-b+1);
        printf("%lld\n",cou);
    }
    return 0;
}

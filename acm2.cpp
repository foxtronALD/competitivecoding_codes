#include<bits/stdc++.h>
using namespace std;
long long int a[1000002];
int main()
{
    int t,n,i;
    int zero,one,other,minus1;
    scanf("%d",&t);
    while(t--)
    {
        zero=0;
        minus1=0;
        one=0;
        other=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            if(0==a[i])
                zero++;
            if(1==a[i])
                one++;
            if(a[i]!=0&&a[i]!=1&&a[i]!=-1)
                other++;
            if(-1==a[i])
                minus1++;
        }
        if(n==1)
        {
            printf("yes\n");
        }
        else if(minus1==1&&other==0)
        {
            if(zero>0||one>0)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(minus1>1&&other==0)
        {
            if(one>0)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if((zero>0||one>0)&&minus1==0)
        {
            if(other<=1)
                printf("yes\n");
            else
                printf("no\n");
        }
        else
            printf("no\n");
    }
    return 0;
}

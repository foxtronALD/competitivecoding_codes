//No two cows can be closely placed together
#include<bits/stdc++.h>
using namespace std;
int check(int);
int sum,i,temp,n,c;
int a[1000000];
int main()
{
    int t,u,l,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        l=0;
        u=a[n-1]-a[0];
        while(l<u)
        {
            mid=(l+u)/2;
            if(check(mid))
            {
                if(mid==l)
                    u=u+1;
                else
                l=mid;
            }
            else
            {
                u=mid-1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
int check(int k)
{
    sum=0;temp=1;
    for(i=1;i<n;i++)
    {
        sum=sum+(a[i]-a[i-1]);
        if(sum>=k)
        {
            temp++;
            sum=0;
        }
    }
    if(temp>=c)
        return 1;
    else
        return 0;
}

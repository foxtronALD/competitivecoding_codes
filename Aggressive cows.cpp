//No two cows can be closely placed together
#include<bits/stdc++.h>
using namespace std;
int check(int);
int *p,cou,avg,c,rem;
int temp,n;
int a[1000000];
int main()
{
    int t,i,j,u;
    int k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n==1||(n<c))
        {
            printf("0\n");
            continue;
        }
        sort(a,a+n);
        avg=(a[n-1]-a[0])/(c-1);
        rem=(a[n-1]-a[0])%(c-1);
        for(u=avg;u>=0;u--)
        {
            if(check(u))
            {
                printf("%d\n",u);
                break;
            }
        }
    }
    return 0;
}
int check(int k)
{
    p=a;
    temp=0;
    cou = 0;
    while(p<(a+n))
    {
        if(binary_search(p,a+n,*p+k))
        {
            cou++;
            temp=1;
        }
        p=lower_bound(p,a+n,*p+avg);
    }
    if(k==avg&&rem==0)
    {
        if(cou==c-1)
            return 1;
        else
            return 0;
    }
    return temp;
}

#include<bits/stdc++.h>
using namespace std;
int a[10000];
int c[10000];
int n;
int main()
{
    scanf("%d",&n);
    int i,k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l,r,sum=0;
    k=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            c[k++]=i;
        }
    }
    if(a[n]==0)
        if(k!=0)
        {
            c[k-1]=n;
        }
    if(k!=0&&c[k-1]!=n)
        c[k++]=n;
    /*for(i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum==0)
        {
            c[k++]=--i;
        }
    }*/
    if(k==0)
        printf("NO");
    else
    {
        printf("YES\n%d\n",k);
        l=1;
        for(i=0;i<k;i++)
        {
            r=c[i];
            printf("%d %d\n",l,r);
            l=r+1;
        }
    }
    return 0;
}

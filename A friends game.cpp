#include<bits/stdc++.h>
using namespace std;
long long int a[1000002];
int root[1000002];
int coun(int n)
{
    int i;
    int co=0;
    for(i=2;i<=n;i++)
    {
        if(a[i]%2)
            co++;
    }
}
int main()
{
    int n,x,i,y,flag;
    int cou=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        root[y]=x;
    }
    for(i=2;i<=n;i++)
    {
        a[i]=a[i]/2;
    }
    flag=0;
    for(i=2;i<=n;i++)
    {
        if(root[i]==1)
            continue;
        if(coun(n)%2==0)
        if((a[i]%2)&&(a[root[i]]%2))
        {
            a[root[i]]++;
            a[i]--;
            if(flag==0)
                flag=1;
            else
                flag=0;
        }
    }
    cou=0;
    for(i=2;i<=n;i++)
    {
        if(a[i]%2)
            cou++;
    }
    if(cou%2&&cou!=0)
    {
        if(flag==0)
            printf("Rachel");
        else
            printf("Ross");
    }
    else
    {
        if(flag==0)
            printf("Ross");
        else
            printf("Rachel");
    }
    return 0;
}

//Same as in the aggressive cows minimum of the maximum is to be calculated
#include<bits/stdc++.h>
using namespace std;
int check(int);
int check2(int);
int sum=0,temp2;
int sum1,i,k,m,temp;
vector <int> v1;
int a[1000000];
int main()
{
    int t,ba;
    int l,u,mid,ma;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&m,&k);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        ma=a[0];
        for(i=0;i<m;i++)
        {
            if(ma<a[i])
                ma=a[i];
        }
        l=ma;
        u=sum;
        while(l<u)
        {
            mid=(l+u)/2;
            if(check(mid))
            {
                u=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        sum=0;
        temp2=check2(u)-k;
        v1.clear();
        for(i=m-1;i>=0;i--)
        {
            sum=sum+a[i];
            if(sum>u)
            {
                sum=a[i];
                v1.push_back(-1);
            }
            v1.push_back(a[i]);
        }
        while(v1.empty()==0)
        {
            ba=v1.back();
            if(ba==-1)
                printf("/ ");
            else if(v1.size()>1)
                printf("%d ",ba);
            else if(v1.size()==1)
                printf("%d",ba);
            v1.pop_back();
            if((v1.back()!=-1)&&(ba!=-1)&&(temp2<0)&&(v1.empty()==0))
            {
                printf("/ ");
                temp2++;
            }
        }
        printf("\n");
    }
    return 0;
}
int check(int c)
{
    sum1=0;
    temp=0;
    for(i=m-1;i>=0;i--)
    {
        sum1=sum1+a[i];
        if(sum1>c)
        {
            sum1=a[i];
            temp++;
        }
    }
    if(sum1!=0)
        temp++;
    if(temp<=k)
        return 1;
    else
        return 0;
}
int check2(int c)
{
    sum1=0;
    temp=0;
    for(i=m-1;i>=0;i--)
    {
        sum1=sum1+a[i];
        if(sum1>c)
        {
            sum1=a[i];
            temp++;
        }
    }
    if(sum1!=0)
        temp++;
    return temp;
}

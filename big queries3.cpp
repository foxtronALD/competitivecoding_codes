#include<bits/stdc++.h>
using namespace std;
int func(long long int x,int y)
{
    int coun=0;
    while(x%y==0)
    {
        x=x/y;
        coun++;
    }
    return coun;
}
int five[1000002];
int two[1000002];
int lazy2[1000002];
int lazy5[1000002];
int two1[1000002];
int five1[1000002];
int data2[1000002];
int data5[1000002];
int range2[1000002];
int range5[1000002];
long long int a[1000002];
int divi(int x,int y)
{
    int sum=0;
    while(x)
    {
        sum=sum+x/y;
        x=x/y;
    }
    return sum;
}
void build(int t,int tree[],int s,int e,int arr[])
{
    if(s>e)
        return ;
    if(s==e)
    {
        tree[t]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    build(2*t,tree,s,mid,arr);
    build(2*t+1,tree,mid+1,e,arr);
    tree[t]=tree[2*t]+tree[2*t+1];
}
int fin(int data[],int lazy[],int t,int tree[],int s,int e,int arr[],int x,int y,int b)
{
    int mid=(s+e)/2;
    if(lazy[t]!=0)
    {
        if(data[t]==1)
        {
            tree[t]+=lazy[t]*(e-s+1);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=1;
            }
        }
        else if(data[t]==2)
        {
            tree[t]=lazy[t]*(e-s+1)+divi(e-arr[t]+1,b)-divi(s-arr[t],b);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=2;
                arr[2*t+1]=arr[2*t]=arr[t];
            }
        }
        arr[t]=0;
        data[t]=0;
        lazy[t]=0;
    }
    if(e<x||s>y||s>e)
    return 0;
    else if(s>=x&&e<=y)
    {
        return tree[t];
    }
    return fin(data,lazy,2*t,tree,s,mid,arr,x,y,b)+fin(data,lazy,2*t+1,tree,mid+1,e,arr,x,y,b);
}
void update1(int data[],int lazy[],int t,int tree[],int s,int e,int arr[],int x,int y,int temp,int b)
{
    int mid=(s+e)/2;
    if(lazy[t]!=0)
    {
        if(data[t]==1)
        {
            tree[t]+=lazy[t]*(e-s+1);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=1;
            }
        }
        else if(data[t]==2)
        {
            tree[t]=lazy[t]*(e-s+1)+divi(e-arr[t]+1,b)-divi(s-arr[t],b);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=2;
                arr[2*t+1]=arr[2*t]=arr[t];
            }
        }
        data[t]=0;
        lazy[t]=0;
        arr[t]=0;
    }
    if(x>e||s>y||s>e)
        return ;
    if(s>=x&&e<=y)
    {
        tree[t]+=temp*(e-s+1);
        if(s!=e)
        {
            lazy[2*t+1]=lazy[2*t]=temp;
            data[2*t+1]=data[2*t]=1;
        }
        return;
    }
    update1(data,lazy,2*t,tree,s,mid,arr,x,y,temp,b);
    update1(data,lazy,2*t+1,tree,mid+1,e,arr,x,y,temp,b);
    tree[t]=tree[2*t]+tree[2*t+1];
}
void update2(int data[],int lazy[],int t,int tree[],int s,int e,int arr[],int x,int y,int temp,int b)
{
    int mid=(s+e)/2;
    if(lazy[t]!=0)
    {
        if(data[t]==1)
        {
            tree[t]+=lazy[t]*(e-s+1);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=1;
            }
        }
        else if(data[t]==2)
        {
            tree[t]=lazy[t]*(e-s+1)+divi(e-arr[t]+1,b)-divi(s-arr[t],b);
            if(s!=e)
            {
                lazy[2*t+1]=lazy[2*t]=lazy[t];
                data[2*t+1]=data[2*t]=2;
                arr[2*t+1]=arr[2*t]=arr[t];
            }
        }
        arr[t]=0;
        data[t]=0;
        lazy[t]=0;
    }
    if(x>e||s>y||s>e)
        return ;
    if(s>=x&&e<=y)
    {
        tree[t]=temp*(e-s+1)+divi(e-x+1,b)-divi(s-x,b);
        if(s!=e)
        {
            lazy[2*t+1]=lazy[2*t]=temp;
            data[2*t+1]=data[2*t]=2;
            arr[2*t+1]=arr[2*t]=x;
        }
        return;
    }
    update2(data,lazy,2*t,tree,s,mid,arr,x,y,temp,b);
    update2(data,lazy,2*t+1,tree,mid+1,e,arr,x,y,temp,b);
    tree[t]=tree[2*t]+tree[2*t+1];
}
int main()
{
    long long int t,n,m,i,z,coun=0;
    int p,q,r;
    long long int s;
    int to,fi;
    scanf("%lld",&t);
    while(t--)
    {
        z=0;
        for(i=1;i<=1000000;i++)
        {
            data2[i]=lazy2[i]=0;
            range2[i]=range5[i]=data5[i]=lazy5[i]=0;
        }
        scanf("%lld%lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            two[i]=func(a[i],2);
            five[i]=func(a[i],5);
        }
        build(1,two1,1,n,two);
        build(1,five1,1,n,five);
        while(m--)
        {
            scanf("%d%d%d",&p,&q,&r);
            if(p==1||p==2)
            {
                scanf("%lld",&s);
                to=func(s,2);
                fi=func(s,5);
                if(p==1)
                {
                    update1(data2,lazy2,1,two1,1,n,range2,q,r,to,2);
                    update1(data5,lazy5,1,five1,1,n,range5,q,r,fi,5);
                }
                else if(p==2)
                {
                    update2(data2,lazy2,1,two1,1,n,range2,q,r,to,2);
                    update2(data5,lazy5,1,five1,1,n,range5,q,r,fi,5);
                }
            }
            else if(p==3)
            {
                z=z+min(fin(data2,lazy2,1,two1,1,n,range2,q,r,2),fin(data5,lazy5,1,five1,1,n,range5,q,r,5));
            }
        }
        printf("%lld\n",z);
    }
    return 0;
}

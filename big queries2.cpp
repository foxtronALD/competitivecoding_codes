#include<bits/stdc++.h>
using namespace std;
long long tree2[400002];
long a[100001];
long long tree5[400002];
int lazy2[400002];
int lazy5[400002];
int lazytree2[400002]={0};
int lazytree5[400002]={0};
int ind[400002];
long long arr1[100002];
long long arr2[100002];
long long func(long long x,int b)
{
    long long i=0;
    while(x%b==0&&x!=0)
    {
        x=x/b;
        i++;
    }
    return i;
}
/*long long func2(long long x,long long b)
{
    long long sum=0;
    while(x>=b)
    {
        sum+=x/b;
        x=x/b;
    }
    return sum;
}*/
void build(long long tree[],long node,int s,int e,int b)
{
    if(s==e)
    {
        tree[node]=func(a[s],b);
        return ;
    }
    int mid=(s+e)/2;
    build(tree,2*node,s,mid,b);
    build(tree,2*node+1,mid+1,e,b);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void updateRange(long long tree[],int lazy[],int lazytree[],int node,int s,int e,int l,int u,long long val,int b)
{
    if(ind[node]!=-1)
    {
        if(b==2)
            tree[node]=arr1[e-ind[node]+1]-arr1[s-ind[node]]+lazytree[node]*(e-s+1);
        else
            tree[node]=arr2[e-ind[node]+1]-arr2[s-ind[node]]+lazytree[node]*(e-s+1);
        if(s!=e)
        {
            lazytree[2*node]=lazytree[node];
            lazytree[2*node+1]=lazytree[node];
            lazy[2*node]=0;
            lazy[2*node+1]=0;
            ind[2*node]=ind[node];
            ind[2*node+1]=ind[node];
        }
        lazytree[node]=0;
        if(b==5)
        {
            ind[node]=-1;
        }
    }
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node]*(e-s+1);
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>e||s>u||e<l)
        return;
    if(s>=l&&e<=u)
    {
        tree[node]+=val*(e-s+1);
        if(s!=e)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    int mid=(s+e)/2;
    updateRange(tree,lazy,lazytree,2*node,s,mid,l,u,val,b);
    updateRange(tree,lazy,lazytree,2*node+1,mid+1,e,l,u,val,b);
    tree[node]=tree[2*node]+tree[2*node+1];
}
long long query(long long tree[],int lazy[],int lazytree[],int node,int s,int e,int l,int u,int b)
{
    if(ind[node]!=-1)
    {
        //prlong longf("Index : %d ",ind[node]);
        if(b==2)
            tree[node]=arr1[e-ind[node]+1]-arr1[s-ind[node]]+lazytree[node]*(e-s+1);
        else
            tree[node]=arr2[e-ind[node]+1]-arr2[s-ind[node]]+lazytree[node]*(e-s+1);
        //prlong longf("Tree : %d ",tree[node]);
        if(s!=e)
        {
            lazytree[2*node]=lazytree[node];
            lazytree[2*node+1]=lazytree[node];
            ind[2*node]=ind[node];
            ind[2*node+1]=ind[node];
            lazy[2*node]=0;
            lazy[2*node+1]=0;
        }
        lazytree[node]=0;
        if(b==5)
        {
            ind[node]=-1;
        }
    }
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node]*(e-s+1);
        //prlong longf("Treelazy : %d ",tree[node]);
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>u||e<l)
        return 0;
    if(s>=l&&e<=u)
    {
        //prlong longf("Yo man\n");
        //prlong longf("Tree : %d ",tree[node]);
        return tree[node];
    }
    int mid=(s+e)/2;
    return (query(tree,lazy,lazytree,2*node,s,mid,l,u,b)+query(tree,lazy,lazytree,2*node+1,mid+1,e,l,u,b));
}
void updateNew(long long tree[],int lazy[],int lazytree[],int node,int s,int e,int l,int u,long long val,int b)
{
    if(ind[node]!=-1)
    {
        if(b==2)
            tree[node]=arr1[e-ind[node]+1]-arr1[s-ind[node]]+lazytree[node]*(e-s+1);
        else
            tree[node]=arr2[e-ind[node]+1]-arr2[s-ind[node]]+lazytree[node]*(e-s+1);
        if(s!=e)
        {
            lazytree[2*node]=lazytree[node];
            lazytree[2*node+1]=lazytree[node];
            ind[2*node]=ind[node];
            ind[2*node+1]=ind[node];
            lazy[2*node]=0;
            lazy[2*node+1]=0;
        }
        lazytree[node]=0;
        if(b==5)
        {
            ind[node]=-1;
        }
    }
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node]*(e-s+1);
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(s>e||s>u||e<l)
        return ;
    if(s>=l&&e<=u)
    {
        if(b==2)
            tree[node]=arr1[e-l+1]-arr1[s-l]+val*(e-s+1);
        else
            tree[node]=arr2[e-l+1]-arr2[s-l]+val*(e-s+1);
        if(s!=e)
        {
            lazy[2*node]=0;
            lazy[2*node+1]=0;
            lazytree[2*node]=val;
            lazytree[2*node+1]=val;
            ind[2*node]=l;
            ind[2*node+1]=l;
        }
        return;
    }
    int mid=(s+e)/2;
    updateNew(tree,lazy,lazytree,2*node,s,mid,l,u,val,b);
    updateNew(tree,lazy,lazytree,2*node+1,mid+1,e,l,u,val,b);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{
    int t,n,m,i,p,q,r;
    long long coun,s;
    scanf("%d",&t);
    for(i=0;i<=100002;i++)
    {
        if(i!=0)
        {
            arr1[i]=arr1[i-1]+func(i,2);
            arr2[i]=arr2[i-1]+func(i,5);
        }
        else
        {
            arr1[i]=func(i,2);
            arr2[i]=func(i,5);
        }
    }
    while(t--)
    {
        memset(ind,-1,sizeof(ind));
        memset(lazy2,0,sizeof(lazy2));
        memset(lazy5,0,sizeof(lazy5));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        build(tree2,1,0,n-1,2);
        build(tree5,1,0,n-1,5);
        coun=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&p);
            if(p==1)
            {
                scanf("%d%d%lld",&q,&r,&s);
                updateRange(tree2,lazy2,lazytree2,1,0,n-1,q-1,r-1,func(s,2),2);
                updateRange(tree5,lazy5,lazytree5,1,0,n-1,q-1,r-1,func(s,5),5);
            }
            else if(p==2)
            {
                scanf("%d%d%lld",&q,&r,&s);
                updateNew(tree2,lazy2,lazytree2,1,0,n-1,q-1,r-1,func(s,2),2);
                updateNew(tree5,lazy5,lazytree5,1,0,n-1,q-1,r-1,func(s,5),5);
            }
            else
            {
                scanf("%d%d",&q,&r);
                coun+=min(query(tree5,lazy5,lazytree5,1,0,n-1,q-1,r-1,5),query(tree2,lazy2,lazytree2,1,0,n-1,q-1,r-1,2));
                //prlong longf("%d\n",coun);
            }
        }
        printf("%lld\n",coun);
        memset(lazytree2,0,sizeof(lazytree2));
        memset(lazytree5,0,sizeof(lazytree5));
        memset(tree2,0,sizeof(tree2));
        memset(tree5,0,sizeof(tree5));
    }
    return 0;
}

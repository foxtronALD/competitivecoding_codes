#include<bits/stdc++.h>
using namespace std;
int a[100002];
int tree[400000][2];
void build(int node,int s,int e)
{
    if(s==e)
    {
        if(a[s]==1)
        {
            tree[node][0]=1;
            tree[node][1]=0;
        }
        else
        {
            tree[node][0]=0;
            tree[node][1]=1;
        }
        return ;
    }
    int mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0]-min(tree[2*node][0],tree[2*node+1][1]);
    tree[node][1]=tree[2*node][1]+tree[2*node+1][1]-min(tree[2*node][0],tree[2*node+1][1]);
}
void update(int node,int s,int e,int index)
{
    if(index==s&&s==e)
    {
        if(a[s]==1)
        {
            a[s]=-1;
            tree[node][0]=0;
            tree[node][1]=1;
        }
        else
        {
            a[s]=1;
            tree[node][1]=0;
            tree[node][0]=1;
        }
        return ;
    }
    int mid=(s+e)/2;
    if(mid>=index)
        update(2*node,s,mid,index);
    else
        update(2*node+1,mid+1,e,index);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0]-min(tree[2*node][0],tree[2*node+1][1]);
    tree[node][1]=tree[2*node][1]+tree[2*node+1][1]-min(tree[2*node][0],tree[2*node+1][1]);
}
int main()
{
    int n,m,x,j;
    char ch;
    for(j=1;j<=10;j++)
    {
        scanf("%d%*c",&n);
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%c",&ch);
            if(ch=='(')
                a[i]=1;
            else
                a[i]=-1;
        }
        build(1,1,n);
        scanf("%d",&m);
        printf("Test %d:\n",j);
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            if(x==0)
            {
                if(n%2)
                    printf("NO\n");
                else if(tree[1][0]==0&&tree[1][1]==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                update(1,1,n,x);
            }
        }
    }
    return 0;
}

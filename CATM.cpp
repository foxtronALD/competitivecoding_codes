#include<bits/stdc++.h>
using namespace std;
queue < pair<int,int> > q;
int a[102][102];
int b[102][102];
int visitedc[102][102];
int visitedm[102][102];
int m,n;
int flag=0;
void bfsc(int x,int y)
{
    pair <int,int> p1;
    p1=make_pair(x,y);
    q.push(p1);
    a[x][y]=0;
    while(!q.empty())
    {
        p1=q.front();
        x=p1.first;
        y=p1.second;
        q.pop();
        if(visitedc[x][y]!=0)
            continue;
        visitedc[x][y]++;
        if(x>0&&visitedc[x-1][y]==0)
        {
            if(a[x-1][y]!=-1)
                a[x-1][y]=min(a[x][y]+1,a[x-1][y]);
            else
                a[x-1][y]=a[x][y]+1;
            q.push(make_pair(x-1,y));
        }
        if(y<m-1&&visitedc[x][y+1]==0)
        {
            if(a[x][y+1]!=-1)
                a[x][y+1]=min(a[x][y+1],a[x][y]+1);
            else
                a[x][y+1]=a[x][y]+1;
            q.push(make_pair(x,y+1));
        }
        if(x<n-1&&visitedc[x+1][y]==0)
        {
            if(a[x+1][y]!=-1)
                a[x+1][y]=min(a[x+1][y],a[x][y]+1);
            else
                a[x+1][y]=a[x][y]+1;
            q.push(make_pair(x+1,y));
        }
        if(y>0&&visitedc[x][y-1]==0)
        {
            if(a[x][y-1]!=-1)
                a[x][y-1]=min(a[x][y-1],a[x][y]+1);
            else
                a[x][y-1]=a[x][y]+1;
            q.push(make_pair(x,y-1));
        }
    }
    return ;
}
int bfsm(int x,int y)
{
    pair <int,int> p1;
    p1=make_pair(x,y);
    q.push(p1);
    int s=x,e=y;
    b[x][y]=0;
    int maze;
    while(!q.empty())
    {
        maze=INT_MIN;
        p1=q.front();
        x=p1.first;
        y=p1.second;
        q.pop();
        if(visitedm[x][y]!=0)
            continue;
        if(a[x][y]<=b[x][y])
        {
            return 1;
        }
        else if(y==0||x==0||y==m-1||x==n-1)
            return 0;
        visitedm[x][y]=1;
        if(x>0&&visitedm[x-1][y]==0)
        {
            if(maze<a[x-1][y])
            {
                s=x-1;
                e=y;
                maze=a[x-1][y];
            }
        }
        if(y<m-1&&visitedm[x][y+1]==0)
        {
            if(maze<a[x][y+1])
            {
                s=x;
                e=y+1;
                maze=a[x][y+1];
            }
        }
        if(x<n-1&&visitedm[x+1][y]==0)
        {
            if(maze<a[x+1][y])
            {
                s=x+1;
                e=y;
                maze=a[x+1][y];
            }
        }
        if(y>0&&visitedm[x][y-1]==0)
        {
            if(maze<a[x][y-1])
            {
                s=x;
                e=y-1;
                maze=a[x][y-1];
            }
        }
        if(visitedm[s][e]==0)
        {
            q.push(make_pair(s,e));
            b[s][e]=b[x][y]+1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    int t,p,q1,r,s,i,j,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&x,&y,&p,&q1,&r,&s);
        memset(a,-1,sizeof(a));
        memset(visitedc,0,sizeof(visitedc));
        bfsc(p-1,q1-1);
        memset(visitedc,0,sizeof(visitedc));
        bfsc(r-1,s-1);
        memset(visitedm,0,sizeof(visitedm));
        if(bfsm(x-1,y-1))
            printf("NO\n");
        else
            printf("YES\n");
        memset(b,0,sizeof(b));
        while(!q.empty())
            q.pop();
    }
    return 0;
}

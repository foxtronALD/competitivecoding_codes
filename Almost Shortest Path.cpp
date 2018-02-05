#include<bits/stdc++.h>
using namespace std;
vector < pair <int ,int > > graph1[100002];
vector < pair <int,int> > graph2[100002];
vector < pair <int,int> > graph3[100002];
int dist1[100002];
int dist2[100002];
priority_queue < pair <int,int> , vector < pair <int,int> > , greater < pair <int,int> > > pq1;
int visited1[1000002];
int visited2[1000002];
int main()
{
    int v,e,i,j,t,p,q,x,y,z;
    scanf("%d %d",&v,&e);
    while(v!=0||e!=0)
    {
        scanf("%d%d",&p,&q);
        for(i=0;i<e;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            graph1[x].push_back(make_pair(y,z));
            graph2[y].push_back(make_pair(x,z));
        }
        memset(visited1,0,sizeof(visited1));
        memset(dist1,-1,sizeof(dist1));
        memset(visited2,0,sizeof(visited2));
        memset(dist2,-1,sizeof(dist2));
        x=p;
        z=0;
        pq1.push(make_pair(0,x));
        dist1[x]=0;
        z=-1;
        while(!pq1.empty())
        {
            z=pq1.top().first;
            x=pq1.top().second;
            pq1.pop();
            if(visited1[x]!=0)
                continue;
            visited1[x]=1;
            for(i=0;i<graph1[x].size();i++)
            {
                if((dist1[graph1[x][i].first]>z+graph1[x][i].second)||(dist1[graph1[x][i].first]==-1))
                {
                    dist1[graph1[x][i].first]=z+graph1[x][i].second;
                    pq1.push(make_pair(z+graph1[x][i].second,graph1[x][i].first));
                }
            }
        }
        x=q;
        z=0;
        pq1.push(make_pair(0,x));
        dist2[x]=0;
        z=-1;
        while(!pq1.empty())
        {
            z=pq1.top().first;
            x=pq1.top().second;
            pq1.pop();
            if(visited2[x]!=0)
                continue;
            visited2[x]=1;
            for(i=0;i<graph2[x].size();i++)
            {
                if((dist2[graph2[x][i].first]>z+graph2[x][i].second)||(dist2[graph2[x][i].first]==-1))
                {
                    dist2[graph2[x][i].first]=z+graph2[x][i].second;
                    pq1.push(make_pair(z+graph2[x][i].second,graph2[x][i].first));
                }
            }
        }
        for(i=0;i<v;i++)
        {
            for(j=0;j<graph1[i].size();j++)
            {
                if((dist1[i]+graph1[i][j].second+dist2[graph1[i][j].first])!=dist1[q])
                {
                    graph3[i].push_back(make_pair(graph1[i][j].first,graph1[i][j].second));
                }
            }
        }
        memset(visited2,0,sizeof(visited2));
        memset(dist2,-1,sizeof(dist2));
        x=p;
        z=0;
        pq1.push(make_pair(0,x));
        dist2[x]=0;
        z=-1;
        while(!pq1.empty())
        {
            z=pq1.top().first;
            x=pq1.top().second;
            pq1.pop();
            if(visited2[x]!=0)
                continue;
            visited2[x]=1;
            for(i=0;i<graph3[x].size();i++)
            {
                if((dist2[graph3[x][i].first]>z+graph3[x][i].second)||(dist2[graph3[x][i].first]==-1))
                {
                    dist2[graph3[x][i].first]=z+graph3[x][i].second;
                    pq1.push(make_pair(z+graph3[x][i].second,graph3[x][i].first));
                }
            }
        }
        printf("%d\n",dist2[q]);
        memset(graph1,0,sizeof(graph1));
        memset(graph2,0,sizeof(graph2));
        memset(graph3,0,sizeof(graph3));
        scanf("%d%d",&v,&e);
    }
    return 0;
}

//First one was disaster
#include<bits/stdc++.h>
using namespace std;
vector < int > edge[100002];
int visited[100002];
int visit[100002];
int visit1[100002];
int main()
{
    int i,j,p,q,ver;
    printf("Enter the number of vertex and edges ");
    int v,e;
    scanf("%d%d",&v,&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&p,&q);
        edge[p].push_back(q);
        edge[q].push_back(p);
    }
    printf("Enter the first vertex ");
    scanf("%d",&ver);
    int k=0,l=1;
    j=1;
    visit[++k]=ver;
    visit1[ver]=1;
    while(l<=v)
    {
        for(i=0;i<edge[visit[j]].size();i++)
        {
            if(edge[visit[j]][i]&&(visit1[edge[visit[j]][i]]==0))
            {
                visit1[edge[visit[j]][i]]=1;
                visit[++k]=edge[visit[j]][i];
            }
        }
        visited[l++]=visit[j++];
    }
    for(i=1;i<=v;i++)
    {
        printf("%d\n",visited[i]);
    }
    return 0;
}

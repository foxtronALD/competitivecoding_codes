#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10000];
vector< pair<int,int> > nodes;
int strength[1000];
int main()
{
    int n,x,y;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&strength[i]);
        nodes.push_back(make_pair(strength[i],i));
    }
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int maxi=INT_MIN;
    for(i=n-1;i>=0;i--)
    {
        nodes[i].first=strength[nodes[i].second];
        if(maxi<nodes[i].first)
            maxi=nodes[i].first;
        for(int j=0;j<graph[nodes[i].second].size();j++)
        {
            strength[graph[nodes[i].second][j]]++;
            for(int k=0;k<graph[graph[nodes[i].second][j]].size();k++)
            {
                strength[graph[graph[nodes[i].second][j]][k]]++;
            }
        }
    }
    printf("%d",maxi);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector <int> v1[50000];
int visited[50000]={0};
int dfs(int index,int flag)
{
    int p=1;
    if(flag==1)
        flag=2;
    else if(flag==2)
        flag=1;
    visited[index]=flag;
    for(int i=0;i<v1[index].size();i++)
    {
        if(visited[v1[index][i]]==0)
            p=dfs(v1[index][i],flag);
        else
        {
            if(flag!=visited[v1[index][i]])
                continue;
            else
                return p=0;
        }
        if(p==0)
            break;
    }
    return p;
}
int main()
{
    int n,m,t,i,j,x,flag=0,y;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        flag=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            v1[x].push_back(y);
            v1[y].push_back(x);
        }
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                if(dfs(i,1)==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        printf("Scenario #%d:\n",j);
        if(flag==1)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        memset(visited,0,sizeof(visited));
        memset(v1,0,sizeof(v1));
    }
    return 0;
}

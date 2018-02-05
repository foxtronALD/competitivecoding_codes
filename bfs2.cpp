//Here we will see how to do the breadth first search
#include<bits/stdc++.h>
using namespace std;
vector <int> graph[100002];
queue <int> st;
int visited[100002];
int main()
{
    printf("Enter the number of vertex\n");
    int v;
    scanf("%d",&v);
    printf("Enter the number of edges\n");
    int e,x,y;
    scanf("%d",&e);
    while(e--)
    {
        scanf("%d%d",&x,&y);
        (graph[x]).push_back(y);
        (graph[y]).push_back(x);
    }
    printf("Enter the starting and ending vertex\n");
    scanf("%d%d",&x,&y);
    st.push(x);
    visited[x]=1;
    while(!st.empty())
    {
        printf("%d\n",st.front());
        x=st.front();
        if(x==y)
            break;
        st.pop();
        for(int i=0;i<(graph[x]).size();i++)
        {
            if(visited[graph[x][i]]==0)
            {
                st.push(graph[x][i]);
                visited[graph[x][i]]=1;
            }
        }
    }
    return 0;
}

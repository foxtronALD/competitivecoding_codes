#include<bits/stdc++.h>
using namespace std;
int mark[100000];
vector < pair <long long int,int> > maximum;
int main()
{
    long long int x;
    int t,i,j,y,n,k,maxi,l;
    scanf("%lld",&t);
    while(t--)
    {
        vector <int> graph[100000];
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            maximum.push_back(make_pair(x,i));
        }
        sort(maximum.begin(),maximum.end());
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(i=1;i<=n;i++)
        {
            k=n-1;
            maxi=0;
            mark[i]=i;
            l=graph[i].size();
            for(j=0;j<l;j++)
            {
                mark[graph[i][j]]=i;
            }
            while(k>=0)
            {
                if(mark[maximum[k].second]!=i)
                {
                    maxi=maximum[k].second;
                    break;
                }
                k--;
            }
            printf("%d ",maxi);
        }
        printf("\n");
        maximum.clear();
        memset(mark,0,sizeof(mark));
    }
    return 0;
}

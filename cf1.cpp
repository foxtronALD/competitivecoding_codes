#include<bits/stdc++.h>
using namespace std;
int visited[1000000];
int main()
{
    int n,i,x,coun=0;
    scanf("%d",&n);
    int maxi=INT_MIN;
    for(i=1;i<=2*n;i++)
    {
        scanf("%d",&x);
        if(visited[x]==1)
            coun--;
        else
        {
            coun++;
            visited[x]++;
        }
        if(maxi<coun)
            maxi=coun;
    }
    printf("%d",maxi);
    return 0;
}

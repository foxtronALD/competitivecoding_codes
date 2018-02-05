#include<bits/stdc++.h>
using namespace std;
int price[1002];
int sol[1002];
int main()
{
    int n,t,i,j,k,mid;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=1;i<=k;i++)
            scanf("%d",&price[i]);
        for(i=1;i<=k;i++)
        {
            if(i)
                mid=(i+1)/2;
            else mid=i/2;
            sol[i]=price[i];
            for(j=i-1;j>=mid;j--)
            {
                if(sol[j]!=-1&&sol[i-j]!=-1)
                {
                    if(sol[i]!=-1)
                    sol[i]=min(sol[i],sol[j]+sol[i-j]);
                    else
                        sol[i]=sol[j]+sol[i-j];
                }
            }
        }
        printf("%d\n",sol[k]);
    }
    return 0;
}

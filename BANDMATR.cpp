#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,sol,j,sum,x;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&x);
                if(x==1)
                    sum++;
            }
        }
        if(sum<=n)
            sol=0;
        else
        {
            sum=sum-n;
            sol=0;
            i=1;
            while(sum>0)
            {
                sum=sum-2*(n-i);
                sol++;
                i++;
            }
        }
        printf("%d\n",sol);
    }
    return 0;
}

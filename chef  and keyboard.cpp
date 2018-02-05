//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int t,n,m,c,i,j,cou,k;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld",&n,&m,&c);
        if(n*m<c)
        {
            printf("0\n");
            continue;
        }
        cou=0;
        j=max(n,m);
        k=min(n,m);
        i=1;
        while(i<=j&&i<=k)
        {
            if(i*j<c)
            i++;
            else if(i*j>c)
                j--;
            else
            {
                if(j<=k&&j!=i)
                   cou=cou+2;
                else
                    cou++;
                    i++;
                    j--;
            }
        }
        printf("%ld\n",cou);
    }
    return 0;
}

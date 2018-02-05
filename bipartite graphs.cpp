#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,d,D,i,n,m,j,k,div,rem,flag=0;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d%d%d%d",&n,&m,&d,&D);
        div=m/n;
        rem=m%n;
        if(rem!=0)
            div++;
        k=1;
        if(div>=d&&div<=D)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(j+i-1!=n)
                    printf("%d %d\n",j,(j+i-1)%(n));
                    else
                        printf("%d %d\n",j,n);
                    if(k<m)
                        k++;
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
        }
        else
            printf("-1\n");
    }
    return 0;
}

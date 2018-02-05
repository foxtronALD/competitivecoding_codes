#include<bits/stdc++.h>
using namespace std;
int a[1000004][18];
int main()
{
    int t,h,k,i,j,maxi;
    int x,n,r,flag,mid;
    int coun;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&h,&k);
        n=1<<h;
        flag=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i][0]);
        r=0;
        coun=0;
        while(n!=1)
        {
            for(i=1;i<=n;i=i+2)
            {
                if((max(a[i][r],a[i+1][r])>a[1][0])&&(max(a[i][r],a[i+1][r])<=(min(a[i][r],a[i+1][r])+k))&&(max(a[i][r],a[i+1][r])>a[1][0]+k))
                {
                    coun++;
                    printf("%d ",min(a[i][r],a[i+1][r]));
                    a[i/2+1][r+1]=min(a[i][r],a[i+1][r]);
                }
                else
                {
                    a[i/2+1][r+1]=max(a[i][r],a[i+1][r]);
                    printf("%d ",max(a[i][r],a[i+1][r]));
                }
            }
            printf("\n");
            n=n/2;
            if(a[1][r+1]!=a[1][0])
            {
                flag=1;
                break;
            }
            r++;
        }
        if(flag==0)
            printf("%d\n",coun);
        else
            printf("-1\n");
    }
    return 0;
}

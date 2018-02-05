#include<bits/stdc++.h>
using namespace std;
int a[402][402]={0};
int main()
{
    int t,n,k,i,j,pre1,pre2,flag=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        k=n;
        i=0;
        j=0;
        pre1=n/2;
        pre2=n/2;
        while(k!=0)
        {
            if(pre1==pre2&&i<n/2)
            {
                a[i++][pre1++]=1;
                k--;
            }
            else if(j<n/2)
            {
                a[pre2++][j++]=1;
                k--;
            }
            else
                break;
        }
        a[n-1][n-1]=1;
        for(i=0;i<n;i++)
        {
            flag=0;
            for(j=0;j<n;j++)
            {
                if(a[i][j]==1)
                    flag=1;
                if(flag==1)
                    a[i][j]=a[i][j-1]+1;
            }
            j=0;
            k=a[i][n-1];
            while(a[i][j]!=1)
            {
                a[i][j]=++k;
                j++;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
                a[i][j]=0;
            }
            printf("\n");
        }
    }
    return 0;
}

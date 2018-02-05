#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,j,i,a[100][101]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x/100][++(a[x/100][0])]=x;
    }
    for(i=0;i<100;i++)
    sort(a[i],a[i]+a[i][0]);
    for(i=0;i<100;i++)
        for(j=1;j<=a[i][0];j++)
    printf("%d ",a[i][j]);
    return 0;
}

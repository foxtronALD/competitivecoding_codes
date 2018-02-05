#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int pos1=INT_MAX,pos2=INT_MAX;
    for(i=m+1;i<=n;i++)
    {
        if(arr[i]!=0&&arr[i]<=k)
        {
            pos1=i;
            break;
        }
    }
    for(i=m-1;i>=1;i--)
    {
        if(arr[i]!=0&&arr[i]<=k)
        {
            pos2=i;
            break;
        }
    }
    printf("%d",10*(min(abs(pos1-m),abs(m-pos2))) );
    return 0;
}

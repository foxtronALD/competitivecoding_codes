#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[100002];
int put[100002];
bool is_safe(int idx,int ar)
{
    for(int i=0;i<idx;i++)
    {
        if(put[i]==ar)
            return false;
    }
    return true;
}
bool func(int idx)
{
    if(idx==n)
        return true;
    if(put[idx]>=0)
    {
        bool ans = func(idx+1);
        if(ans)
            return true;
        else
        {
            put[idx] = -1;
            return false;
        }
    }
    for(int i=idx+1;i<n;i++)
    {
        if(((arr[idx]+arr[i])%k==0)&&is_safe(idx,i))
        {
            put[idx] = i;
            put[i] = idx;
            if(func(idx+1))
                return true;
        }
        put[idx] = -1;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        scanf("%d",&k);
        memset(put,-1,sizeof(put));
        if(func(0))
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500002];
queue <int> q1;
priority_queue <int> q2;
int main()
{
    int n,i,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        q1.push(a[i]);
        if(q2.empty()||q2.top()>=a[i])
            q2.push(a[i]);
        else
        {
            while(!q2.empty())
                q2.pop();
            q2.push(a[i]);
        }
    }
    printf("%d ",q2.top());
    for(i=k+1;i<=n;i++)
    {
        if(q1.front()==q2.top())
        {
            q2.pop();
        }
        q1.pop();
        q1.push(a[i]);
        if(q2.top()>=a[i])
            q2.push(a[i]);
        else
        {
            while(!q2.empty())
                q2.pop();
            q2.push(a[i]);
        }
        printf("%d ",q2.top());
    }
    return 0;
}

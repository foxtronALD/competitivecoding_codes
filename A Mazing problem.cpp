//Use of queue for finding the correct path for the mice
#include<bits/stdc++.h>
using namespace std;
void push(int,int);
void pop();
int row();
int col();
int a[12][12];
int q1[100];
int q2[100];
int top=-1;
int main()
{
    printf("Enter the grid size\n");
    int n,i,j;
    scanf("%d",&n);
    printf("Enter the grid elements\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    i=0;
    for(j=0;j<=n;j++)
    {
        a[i][j]=1;
    }
    for(;i<=n;i++)
        a[i][j]=1;
    for(;j>0;j--)
        a[i][j]=1;
    for(;i>0;i--)
        a[i][j]=1;
    i=1;j=1;
    push(i,j);
    a[1][1]=1;
    while(i<n||j<n)
    {
        if(a[i][j+1]==0)
        {
            j=j+1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i+1][j+1]==0)
        {
            i=i+1;
            j=j+1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i+1][j]==0)
        {
            i=i+1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i+1][j-1]==0)
        {
            i=i+1;
            j=j-1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i-1][j+1]==0)
        {
            i=i-1;
            j=j+1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i-1][j]==0)
        {
            i=i-1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i][j-1]==0)
        {
            j=j-1;
            push(i,j);
            a[i][j]=1;
        }
        else if(a[i-1][j-1]==0)
        {
            i=i-1;
            j=j-1;
            push(i,j);
            a[i][j]=1;
        }
        else
        {
            i=row();
            j=col();
            pop();
        }
    }
    for(i=0;i<=top;i++)
    {
        printf("%d %d\n",q1[i],q2[i]);
    }
    return 0;
}
void push(int val1,int val2)
{
    top++;
    q1[top]=val1;
    q2[top]=val2;
}
void pop()
{
    q1[top]=0;
    q2[top]=0;
    top--;
}
int row()
{
    if(top>0)
        return q1[top-1];
    else
    return -1;
}
int col()
{
    if(top>0)
        return q2[top-1];
    else
    return -1;
}

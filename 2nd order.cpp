#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    int comp;
    int loc;
};
int a[100];
int main()
{
    int n,temp,r;
    printf("Enter the number of the elements in the array\n");
    scanf("%d",&n);
    int i;
    printf("Enter the elements\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    struct node mrf[100][20];
    for(i=1;i<=n;i++)
        mrf[i][0].value=a[i];
    int j;
    temp=n;
    if(temp%2&&temp!=1)
    {
        temp=temp+1;
        mrf[temp][0].value=INT_MAX;
    }
    i=1;
    r=1;
    while(temp!=1)
    {
        j=1;
        for(i=1;i<=temp;i=i+2)
        {
            mrf[j][r].value=min(mrf[i][r-1].value,mrf[i+1][r-1].value);
            mrf[j][r].comp=max(mrf[i][r-1].value,mrf[i+1][r-1].value);
            if(mrf[i][r-1].value<mrf[i+1][r-1].value)
                mrf[j++][r].loc=i;
            else
                mrf[j++][r].loc=i+1;
        }
        temp=j-1;
        if(temp%2&&temp!=1)
        {
            temp=temp+1;
            mrf[temp][r].value=INT_MAX;
        }
        r++;
    }
    int b[100];
    int k=1;
    int location=1;
    for(i=r-1;i>=1;i--)
    {
        b[k++]=mrf[location][i].comp;
        location=mrf[location][i].loc;
    }
    int mrf2[100][20];
    for(i=1;i<k;i++)
        mrf2[i][0]=b[i];
    temp=k-1;
    if(temp%2&&temp!=1)
    {
        mrf2[temp+1][0]=1200;
        temp=temp+1;
    }
    r=1;
    while(temp!=1)
    {
        j=1;
        for(i=1;i<=temp;i=i+2)
        {
            mrf2[j++][r]=min(mrf2[i][r-1],mrf2[i+1][r-1]);
        }
        temp=j-1;
        if(temp%2&&temp!=1)
        {
            temp=temp+1;
            mrf2[temp][r]=INT_MAX;
        }
        r++;
    }
    printf("Second smallest element is : %d",mrf2[1][r-1]);
    return 0;
}

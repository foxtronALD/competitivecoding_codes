#include<bits/stdc++.h>
using namespace std;
int tree[1000000];
int arr[1000000];
int n;
void update(int index,int val)
{
    index+=1;
    while(index<=n)
    {
        tree[index]+=val;
        index+=(index&-index);
    }
}
int cum_sum(int index)
{
    int sum=0;
    while(index>0)
    {
        sum+=tree[index];
        index-=(index&-index);
    }
    return sum;
}
int main()
{
    printf("Enter the number of values in the array\n");
    scanf("%d",&n);
    printf("Enter the values of the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        update(i,arr[i]);
    }
    printf("Enter the number of queries\n");
    int m,x,y;
    scanf("%d",&m);
    printf("Enter the queries\n");
    while(m--)
    {
        scanf("%d%d",&x,&y);
        printf("cum_cum : %d\n",cum_sum(y)-cum_sum(x-1));
    }
    return 0;
}

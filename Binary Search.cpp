#include<stdio.h>
int binary(int *,int,int);
int main()
{
	int b[100];
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&x);
	int z=binary(b,n,x);
	if(z!=-1)
	printf("%d",z+1);
	else
	printf("Not found");
	return 0;
}
int binary(int *a,int size,int k)
{
	int l=0,pos=-1;
	int u=size-1;
	int mid,temp=0;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(a[mid]>k)
		{
			u=mid-1;
		}
		else if(a[mid]<k)
		{
			l=mid+1;
		}
		else if(a[mid]==k)
		{
			pos=mid;
			break;
		}
    }
    return pos;
}

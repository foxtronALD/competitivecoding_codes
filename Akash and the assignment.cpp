#include<stdio.h>
#include<math.h>
char a[1000000];
int squareroot;
int hash[1000][26]={0};
int temphash[26]={0};
int main()
{
	long long int n,q;
	scanf("%lld",&n);
	scanf("%lld",&q);
	squareroot=sqrt(n);
	int j,x=0,y,temp=0;
    scanf("%s",a);
    for(j=0;j<n;j++)
    {
    	if(j>=(x+1)*squareroot)
    		x++;
        hash[x][a[j]-97]++;
	}
	long long int i,l,r,k;
	for(i=0;i<q;i++)
	{
		temp=0;
		for(j=0;j<26;j++)
		temphash[j]=0;
    	scanf("%d%d%d",&l,&r,&k);
    	j=l-1;
        while(j<r)
        {
        	if(j%squareroot!=0)
        	{
        	    temphash[a[j]-97]++;
				j++;	
			}
			else if((j+squareroot)<r)
			{
				for(x=0;x<26;x++)
				{
					temphash[x]=temphash[x]+hash[j/squareroot][x];
				}
				j=j+squareroot;
			}
			else
			{
				temphash[a[j]-97]++;
				j++;
			}
		}
		for(j=1;j<26;j++)
     	{
		    temphash[j]=temphash[j]+temphash[j-1];
     	}
     	for(j=0;j<26;j++)
     	{
     	    if(temphash[j]>=k)
     	    {
     	        printf("%c\n",j+97);
     	        temp=1;
				 break;	
			}
		}
		if(r-l<=k&&temp==0)
		printf("Out of range\n");
	}
	return 0;
}

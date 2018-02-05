//This is chef and the circle run
//Here we will calculate the sum up to n terms of the given array clockwise and anticlockwise
#include<bits/stdc++.h>
using namespace std;
int min1(int *,int);
int min2(int *,int);
int p,minimum,temp1,temp2,temp=0;
int a[1000000];
int c1[1000000]={0};
int c2[1000000]={0};
int a1[1000000]={0};
int a2[1000000]={0};
int main()
{
    int j,k=1,t,i,n=0,s,e;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        temp=0;
        k=1;
        for(j=0;j<=n;j++)
        {
            c1[j]=0;
            c2[j]=0;
            a1[j]=0;
            a2[j]=0;
        }
        scanf("%d",&n);
        if(n==2)
        {
            scanf("%d",&a[1]);
            scanf("%d%d",&s,&e);
            printf("%d",a[1]);
            continue;
        }
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
        }
        scanf("%d%d",&s,&e);
        j=s;
        while(j<e)
        {
            c1[k]=c1[k-1]+a[j];
            k++;
            j++;
        }
        j=e;
        k=1;
        while(j!=s)
        {
            if(j<n+1)
            {
                c2[k]=c2[k-1]+a[j];
                j++;
                k++;
            }
            else
            {
                j=1;
                if(s==1)
                    continue;
                c2[k]=c2[k-1]+a[j];
                k++;
                j++;
            }
        }
        j=s-1;
        k=1;
        while(j!=e-1)
        {
            if(j>0)
            {
                a1[k]=a1[k-1]+a[j];
                j--;
                k++;
            }
            else
            {
                j=n;
                if(e-1==0)
                    continue;
                a1[k]=a1[k-1]+a[j];
                k++;
                j--;
            }
        }
        j=e-1;
        k=1;
        while(j!=s-1)
        {
            a2[k]=a2[k-1]+a[j];
            j--;
            k++;
        }
        int switcha=0;
        int z1;
        int z2;
        temp1=c1[e-s];
        temp2=a1[n-e+s];
            if((z1=min1(c2,n-e+s))<0&&z1<min2(c2,n-e+s))
            {
                temp1+=2*z1;
            }
            else if((z2=min2(c2,n-e+s))<0)
            {
                temp1+=2*z2;
                switcha=1;
            }
            if((z1=min1(a1,n-e+s))<0&&z1<min2(a1,n-e+s))
            {
                if(switcha==0)
                temp1+=2*z1;
            }
            else if((z2=min2(a1,n-e+s))<0)
            {
                if(switcha==0)
                temp1+=2*z2;
            }
            temp=0;
            switcha=0;
            if((z1=min1(a2,e-s))<0&&z1<(min2(a2,e-s)))
            {
                temp2+=2*z1;
            }
            else if((z2=min2(a2,e-s))<0)
            {
                temp2+=2*z2;
                switcha=1;
            }
            if((z1=min1(c1,e-s))<0&&z1<min2(c1,e-s))
            {
                if(switcha==0)
                temp2+=2*z1;
            }
            else if((z2=min2(c1,e-s))<0)
            {
                if(switcha==0)
                temp2+=2*z2;
            }
            printf("%d\n",min(temp1,temp2));
    }
    return 0;
}
int min1(int *b,int size)
{
    if(size%2==0)
    size=size/2;
    else
    {
        if(temp==0)
        {
            size=(size+1)/2;
            temp=1;
        }
        else
            size=size/2;
    }
    minimum=b[1];
    for(p=1;p<=size;p++)
    {
        if(minimum>b[p])
            minimum=b[p];
    }
    return minimum;
}
int min2(int *b,int size)
{
    minimum=b[1];
    for(p=1;p<=size;p++)
    {
        if(minimum>b[p])
            minimum=b[p];
    }
    return minimum;
}

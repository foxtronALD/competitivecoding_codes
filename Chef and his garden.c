//Chef and his garden code chef problem
#include<stdio.h>
int check(int *,int);
void binaryh(int *,int);
void binaryr(int *,int);
int h[1000000];
int r[1000000];
int binh[1000000],binr[1000000];
int i,j;
int main()
{
    int t,n,x,k,q,switcha=0,count,temp=0;
    int start[10],end[10];
    scanf("%d",&t);
    for(x=0;x<t;x++)
    {
        count=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&h[j],&r[j]);
        }
        binaryr(r,n);
        k=0;
        switcha=0;
        q=0;
        if(n>2)
        {
            while(check(h,n)==0)
        {
            for(j=1;j<n-1;j++)
            {
                if(((h[j]>h[j-1])&&(h[j]>h[j+1]))||((h[j]<h[j-1])&&(h[j]<h[j+1])))
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
            for(j=0;j<n;j++)
            {
                h[j]=h[j]+r[j];
            }
            if(temp==1)
            {
                if(switcha==0)
                {
                    start[q]=k;
                    count++;
                }
                switcha=1;
            }
            else
            {
                if(switcha)
                {
                    end[q]=k-1;
                    q++;
                    switcha=0;
                }
            }
            k++;
        }
        for(j=1;j<n-1;j++)
            {
                if(((h[j]>h[j-1])&&(h[j]>h[j+1]))||((h[j]<h[j-1])&&(h[j]<h[j+1])))
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
            if(temp)
            {
                start[q]=k;
                switcha=1;
            }
            else
            {
                end[q]=k-1;
                switcha=0;
            }
        }
        else
        {
            while(check(h,n)==0)
            {
                if(h[0]!=h[1])
                    temp=1;
                else
                {
                    temp=0;
                }
                for(j=0;j<n;j++)
                {
                    h[j]=h[j]+r[j];
                }
                if(temp==1)
                {
                    if(switcha==0)
                    {
                       start[q]=k;
                       count++;
                    }
                    switcha=1;
                }
                else
                {
                    if(switcha)
                    {
                        end[q]=k-1;
                        q++;
                    }
                    switcha=0;
                }
                k++;
            }
            if(h[0]!=h[1])
            {
                count++;
                start[q]=k;
                switcha=1;
            }
            else
            {
                end[q]=k-1;
                switcha=0;
            }

        }
        printf("%d\n",count);
        if(switcha==1)
        {
            for(i=0;i<count-1;i++)
            {
                printf("%d %d\n",start[i],end[i]);
            }
            printf("%d Inf\n",start[i],end[i]);
        }
        else
        {
            for(i=0;i<count;i++)
                printf("%d %d\n",start[i],end[i]);
        }
    }
    return 0;
}
void binaryh(int *b,int size)
{
    if(b[0]>b[1])
    {
        binh[0]=1;
    }
    else
    {
        binh[0]=0;
    }
        for(i=1;i<size;i++)
        {
            if(b[i]<b[i-1])
                binh[i]=0;
            else if(b[i]>b[i-1])
                binh[i]=1;
            else
                binh[i]=binh[i-1];
        }
}
void binaryr(int *b,int size)
{
    if(b[0]>b[1])
    {
        binr[0]=1;
    }
    else
    {
        binr[0]=0;
    }
        for(i=1;i<size;i++)
        {
            if(b[i]<b[i-1])
                binr[i]=0;
            else if(b[i]>b[i-1])
                binr[i]=1;
            else
                binr[i]=binr[i-1];
        }
}
int check(int *b,int size)
{
    binaryh(b,size);
    int c=0;
    for(i=0;i<size;i++)
    {
        if(binr[i]==binh[i])
            c=1;
        else
            c=0;
    }
    return c;
}

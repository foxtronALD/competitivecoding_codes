//Don't know how to proceed....
#include<bits/stdc++.h>
using namespace std;
int compare(const void *,const void *);
struct node
{
    int a;
    int b;
    int c;
};
struct node det[102];
int main()
{
    int n,m,i,x,y,z,k,sum=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        det[i].a=x;
        det[i].b=y;
        det[i].c=z;
        sum=sum+x;
    }
    qsort(det,n,sizeof(struct node),compare);
    for(i=0;i<n;i++)
    {
        printf("%d\n",det[i].c);
    }
    /*sum=m*n-sum;
    int tt=0,t;
    for(i=n-1;i>=0;i--)
    {
        t=0;
        while(sum-(det[i].c)>0&&(det[i].b-((det[i].a)+((det[i].c)*t)))>0)
        {
            sum=sum-det[i].c;
            t++;
            tt++;
        }
        if(sum<=0)
        {
            break;
        }
    }
    if(sum>0)
        tt++;
    printf("%d",tt);*/
    return 0;
}
int compare(const void *e1,const void *e2)
{
    struct node *p1=(struct node *)e1;
    struct node *p2=(struct node *)e2;
    {
        return (p1->c)-(p2->c);
    }
}

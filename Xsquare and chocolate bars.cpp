#include<bits/stdc++.h>
using namespace std;
int maxi(int *,int);
char str[1000002];
int len[1000002];
int main()
{
    int t,i,flag,length,time;
    scanf("%d%*c",&t);
    while(t--)
    {
        //time=0;
    scanf("%s",str);
    length=strlen(str);
    for(i=0;i<length;i++)
    {
        if(i<2)
            continue;
        flag=0;
        if(str[i]*1!=str[i-1])
            flag=1;
        else if(str[i]*1!=str[i-2])
            flag=1;
        if(flag==1)
        {
            //if(time==2)
            if(len[i-1]==len[i-2])
            {
                //time=0;
                len[i]=len[i-3]+3;
                //printf("%d ",len[i]);
            }
            //else if(time>2)
            //{
//                len[i]=0;
  //              time=0;
        //}
            else
            {
                //time++;
                len[i]=0;
                //printf("%d ",len[i]);
            }
        }
        else
        {
            //time++;
            len[i]=0;
            //printf("%d ",len[i]);
        }
    }
    printf("%d\n",length-maxi(len,length));
    }
    return 0;
}
int maxi(int *b,int n)
{
    int ma=b[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(ma<b[i])
            ma=b[i];
    }
    return ma;
}

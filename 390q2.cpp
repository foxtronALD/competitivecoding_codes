#include<bits/stdc++.h>
using namespace std;
int a[5][5];
int main()
{
    char ch;
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%c",&ch);
            if(ch=='x')
                a[i][j]=1;
            else if(ch=='o')
                a[i][j]=0;
            else
                a[i][j]=-1;
        }
        scanf("%*c");
    }
    /*for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==1)
            {
                if(i-1>=0&&a[i-1][j]==1)
                    a[i][j]=a[i-1][j]=2;
                else if(i-1>=0&&j+1<=3&&a[i-1][j+1]==1)
                    a[i][j]=a[i-1][j+1]=2;
                else if(j+1<=3&&a[i][j+1]==1)
                    a[i][j]=a[i][j+1]=2;
                else if(i+1<=3&&j<4&&a[i+1][j+1]==1)
                    a[i][j]=a[i+1][j+1]=2;
                else if(i<4&&a[i+1][j]==1)
                    a[i][j]=a[i+1][j]=2;
                else if(j-1>=0&&i+1<4&&a[i+1][j-1]==1)
                    a[i][j]=a[i+1][j-1]=2;
                else if(j-1>=0&&a[i][j-1]==1)
                    a[i][j]=a[i][j-1]=2;
                else if(j-1>=0&&i-1>=0&&a[i-1][j-1]==1)
                    a[i][j]=a[i][j-1]=2;
            }
        }
    }*/
    flag=0;
    for(i=0;i<4;i++)
    {
        //printf("WTF!!");
        for(j=0;j<4;j++)
        {
            if(a[i][j]==-1)
            {
                if(i-1>=0&&a[i-1][j]==1)
                     {
                         if(i-2>=0&&a[i-2][j]==1)
                            flag=1;
                         else if(i+1<4&&a[i+1][j]==1)
                            flag=1;
                     }
                if(i-1>=0&&j+1<=3&&a[i-1][j+1]==1)
                     {
                         if(i-2>=0&&j+2<4&&a[i-2][j+2]==1)
                            flag=1;
                        else if(i+1<4&&j-1>=0&&a[i+1][j-1]==1)
                            flag=1;
                     }
                if(j+1<=3&&a[i][j+1]==1)
                    {
                         if(j+2<4&&a[i][j+2]==1)
                            flag=1;
                        else if(j-1>=0&&a[i][j-1]==1)
                            flag=1;
                     }
                if(i+1<=3&&j<4&&a[i+1][j+1]==1)
                    {
                         if(i+2<4&&j+2<4&&a[i+2][j+2]==1)
                            flag=1;
                          else if(i-1>=0&&j-1>=0&&a[i-1][j-1]==1)
                            flag=1;
                     }
                if(i<4&&a[i+1][j]==1)
                    {
                         if(i+2<4&&a[i+2][j]==1)
                            flag=1;
                        else if(i-1>=0&&a[i-1][j]==1)
                            flag=1;
                     }
                if(j-1>=0&&i+1<4&&a[i+1][j-1]==1)
                    {
                         if(i+2<4&&j-2>=0&&a[i+2][j-2]==1)
                            flag=1;
                        else if(i-1>=0&&j+1<4&&a[i-1][j+1]==1)
                            flag=1;
                     }
                if(j-1>=0&&a[i][j-1]==1)
                    {
                        //printf("hello");
                         if(j-2>=0&&a[i][j-2]==1)
                         {
                             flag=1;
                             //printf("Yo %d",flag);
                         }

                        else if(j+1<4&&a[i][j+1]==1)
                            flag=1;
                     }
                if(j-1>=0&&i-1>=0&&a[i-1][j-1]==1)
                    {
                         if(i-2>=0&&j-2>=0&&a[i-2][j-2]==1)
                            flag=1;
                        else if(i+1<4&&j+1<4&&a[i+1][j+1]==1)
                            flag=1;
                     }
            }
        }
        //printf("%d",flag);
    }
    if(flag==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

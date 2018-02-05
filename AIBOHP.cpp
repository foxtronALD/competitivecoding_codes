//This problem of spoj actually meant to determine the longest palindrome.
//Longest palindrome can be found by two methods one by using simple dp and another by
//Determining the longest common subsequence in the string and the reverse of the string
//Nut simple dp approach as thought could not be applied
//This is lcs approach
#include<bits/stdc++.h>
using namespace std;
char a[100002];
char b[100002];
int l[6101][6101];//Array to determine the longest palindrome and stores length of palindrome
int lcs(char *x,char *y,int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                l[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                l[i][j]=1+l[i-1][j-1];
            }
            else
            {
                l[i][j]=max(l[i][j-1],l[i-1][j]);
            }
        }
    }
    return l[n][m];
}
void rev(char *x,char *y,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        y[n-i-1]=x[i];
    }
}
int main()
{
    int t,length,i,maxi,j;
    scanf("%d%*c",&t);
    while(t--)
    {
        scanf("%s",a);
        length=strlen(a);
        rev(a,b,length);
        printf("%d\n",length-lcs(a,b,length,length));
    }
    return 0;
}

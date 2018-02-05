#include<bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000];
int dp[105][105];
int main()
{
    int i,j;
    while(scanf("%s %s%*c",a,b)!=EOF)
    {
        n=strlen(a);
        m=strlen(b);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0||j==0)
                {
                    if(a[i]==b[j])
                        dp[i][j]=1;
                    else

                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char str[50000];
long long int dp[50000];
int n;
int main()
{
    scanf("%s",str);
    int i;
    while(strcmp(str,"0")!=0)
    {
        n=strlen(str);
        dp[0]=1;
        for(i=1;i<n;i++)
        {
            if(i==1)
            {
                if(((str[i-1]==50&&str[i]<=54)||(str[i-1]<=49&&str[i]<=57))&&str[i]!='0'&&str[i-1]!='0')
                    dp[i]=1+dp[i-1];
                else if(str[i]=='0'&&(str[i-1]>50||str[i-1]=='0'))
                {
                    dp[n-1]=0;
                    break;
                }
                else
                    dp[i]=dp[i-1];
                continue;
            }
            if(str[i-1]=='0'&&str[i]=='0')
            {
                dp[n-1]=0;
                break;
            }
            if(((str[i-1]==50&&str[i]<=54)||(str[i-1]<=49&&str[i]<=57))&&str[i-1]!='0')
            {
                if(str[i]!='0')
                    dp[i]=dp[i-1]+dp[i-2];
                else
                    dp[i]=dp[i-2];
            }
            else if(str[i]!='0')
                dp[i]=dp[i-1];
            else if(str[i]=='0')
            {
                dp[n-1]=0;
                break;
            }
        }
        printf("%lld\n",dp[n-1]);
        memset(dp,0,sizeof(dp));
        scanf("%s",str);
    }
    return 0;
}

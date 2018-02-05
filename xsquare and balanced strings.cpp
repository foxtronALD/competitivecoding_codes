//Here i don't know how to solve this problem with dynamic programming
#include<bits/stdc++.h>
using namespace std;
int freq[26];
int main()
{
    int t,flag;
    char arr[1000000];
    int i,cou;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<26;i++)
            freq[i]=0;
        scanf("%*c%s",arr);
        int n=strlen(arr);
        for(i=0;i<n;i++)
        {
            freq[arr[i]-97]++;
        }
        cou=0;
        while(1)
        {
            flag=0;
            for(i=0;i<26;i++)
            {
                if(freq[i]%2)
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
            }
            if(flag==0)
            for(i=0;i<26;i++)
            {
                freq[i]=freq[i]/2;
            }
            else
                break;
            cou++;
        }
        if(cou==0)
        printf("-1\n");
        else
        printf("%d\n",cou);
    }
    return  0;
}

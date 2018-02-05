//Here we will assign a binary representation of the number 5,6
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,num1;
    vector <int> v1;
    long long k,res,j;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&k);
        num1=log2(k+2)-1;
        res=k-2*(long long)pow(2,num1)+1;
        if(res<0)
        {
            num1=num1-1;
            res=k-2*(long long)pow(2,num1)+1;
        }
        for(j=0;j<num1+1;j++)
        {
            if(res&(1<<j))
            {
                v1.push_back(6);
            }
            else
            {
                v1.push_back(5);
            }
        }
        while(v1.empty()==0)
        {
            printf("%d",v1.back());
            v1.pop_back();
        }
        printf("\n");
    }
    return 0;
}

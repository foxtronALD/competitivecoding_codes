#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> v1[101];
int func(int index,int mask)
{
    if(index==101)
    {
        if(mask==(1<<n)-1)
            return 1;
        else
            return 0;
    }
    int ans+=func(index+1,mask);
    for(i=0;i<v1[index].size();i++)
    {
        if((1<<v1[index][i])&mask==0)
        {
            ans+=func(index+1,mask|1<<v1[index][i]);
        }
    }
    return ans;
}
int main()
{

    return 0;
}

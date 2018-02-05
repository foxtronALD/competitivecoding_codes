//Simple code to tell what was the earlier positions of the elements of the array after sorting.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <int,int> m1;
    int temp,i,n;
    printf("Enter the no of the terms in the array\n");
    cin >> n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        m1[temp]=i;
    }
    map <int,int> ::iterator it=m1.begin();
    while(it!=m1.end())
    {
        printf("%d ",it->second);
        it++;
    }
    return 0;
}

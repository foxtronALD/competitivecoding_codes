#include<bits/stdc++.h>
using namespace std;
vector < pair<int,double> > v1;
int a[100000];
int b[100000];
double rel[100000];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(i=0;i<n;i++)
    {
        v1.push_back(make_pair(a[i],(double)b[i]));
    }
    sort(v1.begin(),v1.end());
    int last=v1[n-1].first;
    i=n-2;
    stack <double> st;
    st.push(v1[n-1].second);
    while(last==v1[i].first)
    {
        st.push(v1[i].second);
        i--;
    }
    i++;
    for(int j=n-1;j>=i;j--)
    {
        v1[j].second=st.top();
        st.pop();
    }
    for(i=0;i<n-1;i++)
        v1[i].second=v1[i].second+v1[n-1].second;
    for(i=0;i<n-1;i++)
    {
        rel[i]=(double)(v1[n-1].first-v1[i].first)/(v1[i].second);
    }
    double maxi=rel[0];
    for(i=0;i<n-1;i++)
        if(maxi<rel[i])
        maxi=rel[i];
    printf("%.12lf",maxi);
    return 0;
}

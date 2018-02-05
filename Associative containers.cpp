#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <string> name;
    name.push_back("Arpit");
    name.push_back("Gupta");
    name.push_back("Ritik");
    int n=name.size();
    int m=name.capacity();
    string str = name[1];
    vector <string> :: iterator it = name.begin();
    string last = name.back();
    int n2 = name.size();
    printf("Size of vector = %d\n",n);
    printf("Capacity of vector = %d\n",m);
    cout << "Second string = " << *(it + 1) << endl;
    cout << "Last string = "<< *(it+name.size()) << endl;
    printf("Remaining size = %d",n2);
    it=name.begin();
    name.insert(it,name.begin(),name.end());
    //for(int i=0;i<name.size();i++)
        //cout << *(it + i) << endl;
    return 0;
}

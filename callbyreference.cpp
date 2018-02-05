#include<iostream>
#include<stdio.h>
using namespace std;
void func(int& a,int& b,int& c)
{
    c = a+b;
    printf("Sum calculated here is %d\n",c);
}
int main()
{
    cout<<"Enter 2 numbers"<<endl;
    int a,b,c;
    cin>>a>>b;
    func(a,b,c);
    printf("The result of the sum is %d\n",c);
    return 0;
}

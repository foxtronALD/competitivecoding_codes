#include<bits/stdc++.h>
using namespace std;
int n;
void func(char str[],int index)
{
    if(index==n)
    {
        str[index]='\0';
        printf("%s\n",str);
        return ;
    }
    char ch;
    for(int i=index;i<n;i++)
    {
        ch=str[i];
        str[i]=str[index];
        str[index]=ch;
        func(str,index+1);
        ch=str[i];
        str[i]=str[index];
        str[index]=ch;
    }
}
int main()
{
    printf("Enter the string\n");
    char str[1000];
    scanf("%s",str);
    n=strlen(str);
    func(str,0);
    return 0;
}

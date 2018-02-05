//Here will implement the searching and deleting of the nodes
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    struct node *lchild=NULL;
    struct node *rchild=NULL;
};
void ins(struct node *ptr,int data)
{
    if(ptr==NULL)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->value=data;
        return;
    }
    if(ptr->value<data)
        return ins(ptr->rchild);
    else if(ptr->value>data)
        return ins(ptr->lchild);
}
int main()
{
    int n;
    printf("Enter the number of elements\n");
    int i;
    struct node *root=NULL;
    for(i=0;i<n;i++)
    {
        ins(root);
    }
    return 0;
}

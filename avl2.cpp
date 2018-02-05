#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    struct node* lchild;
    struct node* rchild;
    int height;
};
int height(struct node* root)
{
    if(root==NULL)
        return 0;
    else
        return root->height;
}
struct node* newnode(int k)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->val=k;
    root->lchild=NULL;
    root->rchild=NULL;
    root->height=1;
    return root;
}
struct node* leftrotate(struct node* root)
{
    struct node* aptr=root->rchild;
    root->rchild=aptr->lchild;
    aptr->lchild=root;
    root->height=max(height(root->lchild),height(root->rchild))+1;
    aptr->height=max(height(aptr->lchild),height(aptr->rchild))+1;
    return aptr;
}
struct node* rightrotate(struct node* root)
{
    struct node* aptr=root->lchild;
    root->lchild=aptr->rchild;
    aptr->rchild=root;
    root->height=max(height(root->lchild),height(root->rchild))+1;
    aptr->height=max(height(aptr->lchild),height(aptr->rchild))+1;
    return aptr;
}
int getbalance(struct node* ptr)
{
    if(ptr!=NULL)
    return height(ptr->lchild)-height(ptr->rchild);
    else
        return NULL;
}
struct node* ins(struct node* ptr,int data)
{
    if( ptr == NULL )
    return newnode(data);
    if( data < ptr->val )
        ptr->lchild=ins(ptr->lchild,data);
    else
        ptr->rchild=ins( ptr->rchild , data );
    ptr->height = max( height(ptr->lchild),height(ptr->rchild)) + 1;
    int balance = height(ptr->lchild) - height(ptr->rchild);
    if( balance>1 && (data < ptr->lchild->val) )
        return ptr=rightrotate(ptr);
    if( balance<-1 && data > ptr->rchild->val )
        return ptr=leftrotate(ptr);
    if( balance>1 && data > ptr->lchild->val )
    {
        ptr->lchild = leftrotate(ptr->lchild);
        return ptr = rightrotate(ptr);
    }
    if( balance<-1 && data < ptr->rchild->val )
    {
        ptr->rchild=rightrotate(ptr->rchild);
        return ptr=leftrotate(ptr);
    }
    return ptr;
}
struct node* del(struct node* ptr,int data)
{
    if(ptr==NULL)
        return ptr;
    if(ptr->val>data)
        ptr->lchild=del(ptr->lchild,data);
    else if(ptr->val<data)
        ptr->rchild=del(ptr->rchild,data);
    else
    {
        if(ptr->lchild==NULL||ptr->rchild==NULL)
        {
            struct node* temp=ptr;
            if(ptr->lchild!=NULL)
            {
                ptr=ptr->lchild;
            }
            else if(ptr->rchild!=NULL)
                ptr=ptr->rchild;
            else
                ptr=NULL;
            free(temp);
        }
        else
        {
            struct node* temp=ptr;
            ptr=ptr->rchild;
            while(ptr->lchild!=NULL)
                ptr=ptr->lchild;
            temp->val=ptr->val;
            temp->rchild=del(temp->rchild,ptr->val);
            ptr=temp;
        }
    }
    if(ptr==NULL)
        return ptr;
    ptr->height=max(height(ptr->lchild),height(ptr->rchild))+1;
    int balance=height(ptr->lchild)-height(ptr->rchild);
    if( balance>1 && getbalance(ptr->lchild)>=0)
        return ptr=leftrotate(ptr);
    if( balance<-1 && getbalance(ptr->rchild)<=0)
        return ptr=leftrotate(ptr);
    if( balance>1 && getbalance(ptr->lchild)<0 )
    {
        if(ptr->lchild->rchild!=NULL)
        ptr->lchild = leftrotate(ptr->lchild);
        return ptr = rightrotate(ptr);
    }
    if( balance<-1 && getbalance(ptr->rchild)>0 )
    {
        if(ptr->rchild->lchild!=NULL)
        ptr->rchild=rightrotate(ptr->rchild);
        return ptr=leftrotate(ptr);
    }
    return ptr;
}
void inorder(struct node* root)
{
    if(root==NULL)
        return ;
    inorder(root->lchild);
    printf("%d ",root->val);
    inorder(root->rchild);
}
int main()
{
    printf("Enter the number of elements you want to insert\n");
    int n,x;
    scanf("%d",&n);
    int i;
    struct node* root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=ins(root,x);
    }
    inorder(root);
    del(root,3);
    del(root,5);
    inorder(root);
    return 0;
}

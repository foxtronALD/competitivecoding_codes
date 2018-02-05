#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    int balance;
    struct node *lchild;
    struct node *rchild;
};
queue < struct node* > q1;
struct node* rotateright(struct node* pptr)
{
    struct node* aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    aptr->rchild=pptr;
    return aptr;
}
struct node* rotateleft(struct node* pptr)
{
    struct node* bptr=pptr->rchild;
    pptr->rchild=bptr->lchild;
    bptr->lchild=pptr;
    return bptr;
}
struct node* insert_leftbalance(struct node* pptr)
{
    struct node* aptr;
    aptr=pptr->lchild;
    if(aptr->balance==1)
    {
        pptr->balance=0;
        aptr->balance=0;
        pptr=rotateright(pptr);
    }
    else
    {
        struct node* bptr=aptr->rchild;
        switch(bptr->balance)
        {
            case -1: pptr->balance=0;
            aptr->balance=1;
            break;
            case 1: pptr->balance=-1;
            aptr->balance=0;
            break;
            case 0: pptr->balance=0;
            aptr->balance=0;
        }
        pptr->lchild=rotateleft(aptr);
        pptr=rotateright(pptr);
    }
    return pptr;
}
struct node* insert_left_check(struct node* pptr,int* taller)
{
    switch(pptr->balance)
    {
        case 0: pptr->balance=1;
        *taller=1;
        break;
        case -1:pptr->balance=0;
        *taller=0;
        break;
        case 1:pptr=insert_leftbalance(pptr);
        *taller=0;
    }
    return pptr;
}
struct node* insert_rightbalance(struct node* pptr)
{
    struct node* aptr;
    aptr=pptr->rchild;
    if(aptr->balance==-1)
    {
        pptr->balance=0;
        aptr->balance=0;
        pptr=rotateleft(pptr);
    }
    else
    {
        struct node* bptr=aptr->lchild;
        switch(bptr->balance)
        {
            case -1: pptr->balance=0;
            aptr->balance=1;
            break;
            case 1: pptr->balance=-1;
            aptr->balance=0;
            break;
            case 0: pptr->balance=0;
            aptr->balance=0;
        }
        pptr->rchild=rotateright(aptr);
        pptr=rotateleft(pptr);
    }
    return pptr;
}
struct node* insert_right_check(struct node* pptr,int* taller)
{
    switch(pptr->balance)
    {
        case 0: pptr->balance=-1;
        *taller=1;
        break;
        case 1:pptr->balance=0;
        *taller=0;
        break;
        case -1:pptr=insert_rightbalance(pptr);
        *taller=0;
    }
    return pptr;
}
void levelorder(struct node* root)
{
    struct node* x;
    if(root!=NULL)
    q1.push(root);
    while(!q1.empty())
    {
        x=q1.front();
        printf("%d ",x->value);
        q1.pop();
        if(x->lchild!=NULL)
        q1.push(x->lchild);
        if(x->rchild!=NULL)
        q1.push(x->rchild);
    }
}
struct node* ins(struct node* pptr,int ikey)
{
    static int taller;
    if(pptr==NULL)
    {
        pptr=(struct node*)malloc(sizeof(struct node));
        pptr->value=ikey;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        pptr->balance=0;
        taller=1;
    }
    else if(pptr->value>ikey)
    {
        pptr->lchild=ins(pptr->lchild,ikey);
        if(taller==1)
            pptr=insert_left_check(pptr,&taller);
    }
    else if(pptr->value<ikey)
    {
        pptr->rchild=ins(pptr->rchild,ikey);
        if(taller==1)
            pptr=insert_right_check(pptr,&taller);
    }
    return pptr;
}
struct node* delete_leftbalance(struct node* pptr)
{
    struct node* aptr=pptr->rchild;
    if(aptr->balance==-1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=rotateleft(pptr);
    }
    else if(aptr->balance==0)
    {
        aptr->balance=1;
        pptr->balance=-1;
        pptr=rotateright(pptr);
    }
    else/*if aptr->balance==1*/
    {
        struct node* bptr=aptr->lchild;
        switch(bptr->balance)
        {
            case 0:aptr->balance=0;
            pptr->balance=0;
            bptr->balance=0;
            break;
            case 1:aptr->balance=-1;
            bptr->balance=0;
            pptr->balance=0;
            break;
            case -1:aptr->balance=0;
            pptr->balance=1;
            bptr->balance=0;
        }
        pptr->rchild=rotateright(pptr->rchild);
        pptr=rotateleft(pptr);
    }
    return pptr;
}
struct node* delete_rightbalance(struct node* pptr)
{
    struct node* aptr=pptr->lchild;
    if(aptr->balance==1)
    {
        aptr->balance=0;
        pptr->balance=0;
        pptr=rotateleft(pptr);
    }
    else if(aptr->balance==0)
    {
        aptr->balance=-1;
        pptr->balance=1;
        pptr=rotateright(pptr);
    }
    else/*if aptr->balance==1*/
    {
        struct node* bptr=aptr->lchild;
        switch(bptr->balance)
        {
            case 0:aptr->balance=0;
            pptr->balance=0;
            bptr->balance=0;
            break;
            case 1:aptr->balance=0;
            bptr->balance=0;
            pptr->balance=-1;
            break;
            case -1:aptr->balance=1;
            pptr->balance=0;
            bptr->balance=0;
        }
        pptr->lchild=rotateleft(pptr->rchild);
        pptr=rotateright(pptr);
    }
    return pptr;
}
struct node* delete_left_check(struct node* pptr,int *pshorter)
{
    switch(pptr->balance)
    {
        case 0:pptr->balance=-1;
        *pshorter=0;
        break;
        case 1:pptr->balance=0;
        *pshorter=1;
        break;
        case -1:pptr=delete_leftbalance(pptr);
        *pshorter=0;
    }
    return pptr;
}
struct node* delete_right_check(struct node* pptr,int *pshorter)
{
    switch(pptr->balance)
    {
        case 0:pptr->balance=1;
        *pshorter=0;
        break;
        case -1:pptr->balance=0;
        *pshorter=1;
        break;
        case 1:pptr=delete_leftbalance(pptr);
        *pshorter=0;
    }
    return pptr;
}
struct node* del(struct node* pptr,int ikey)
{
    static int shorter;
    struct node* tmp=pptr;
    if(tmp->value>ikey)
    {
        tmp=del(tmp->lchild,ikey);
        if(shorter==1)
            tmp=delete_left_check(tmp,&shorter);
    }
    else if(tmp->value<ikey)
    {
        tmp=del(tmp->rchild,ikey);
        if(shorter==1)
            tmp=delete_left_check(tmp,&shorter);
    }
    else/*when it becomes equal*/
    {
        if(pptr->lchild!=NULL&&pptr->rchild!=NULL)
        {
            struct node* abtr=pptr->rchild;
            while(abtr->lchild!=NULL)
                abtr=abtr->lchild;
            pptr->value=abtr->value;
            pptr->rchild=del(pptr->rchild,pptr->value);
            if(shorter==1)
            pptr=delete_left_check(pptr,&shorter);
        }
        else
        {
            if(pptr->rchild!=NULL)
            {
                pptr->value=pptr->rchild->value;
                free(pptr->rchild);
                pptr->rchild=NULL;
            }
            else if(pptr->lchild!=NULL)
            {
                pptr->value=pptr->lchild->value;
                free(pptr->lchild);
                pptr->lchild=NULL;
            }
            else
            {
                pptr=NULL;
                free(tmp);
            }
            shorter=1;
        }
    }
    return pptr;
}
int main()
{
    printf("Enter the number of vertex in the tree\n");
    int n,x;
    struct node* root=NULL;
    scanf("%d",&n);
    printf("Enter the vertex\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=ins(root,x);
    }
    levelorder(root);
    printf("Enter the node you want to delete\n");
    scanf("%d",&x);
    del(root,x);
    levelorder(root);
    return 0;
}

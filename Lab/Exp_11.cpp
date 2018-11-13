using namespace std;
#include<iostream>
#include<queue>
#include<stack>
class tree
{
    struct BST
    {
        int info;
        struct BST *left;
        struct BST *right;
    };
    struct BST *root=NULL;
    struct BST *check;
    struct BST *new_node;
public:
    BST* get()
    {
        return root;
    }
    void create()
    {
        int num;
        cout<<"enter values."<<endl<<"Press 0 to exit."<<endl;
        cin>>num;
        while(num!=0)
        {
           new_node=new BST;
           new_node->info=num;
           new_node->left=NULL;
           new_node->right=NULL;
           if(root==NULL)
           {
               root=new_node;
           }
           else
           {
               check=root;
               while(1)
               {
               if(check->info<num)
               {
                   if(check->right==NULL)
                   {
                       check->right=new_node;
                       cout<<"Parent is:"<<check->info<<endl;
                       break;
                   }
                   else
                   {
                       check=check->right;
                   }
               }
               else
               {
                   if(check->left==NULL)
                   {
                       check->left=new_node;
                       cout<<"Parent is:"<<check->info<<endl;
                       break;
                   }
                   else
                   {
                       check=check->left;
                   }
               }
               }
           }
           cin>>num;
        }
    }
    void del_leafnode(BST *ptr,BST *par)
    {
        if(ptr->info<par->info)
            par->left=NULL;
        else
            par->right=NULL;
        delete ptr;
    }
    void del_singlenode(BST *ptr,BST *par)
    {
        if(ptr->info<par->info)
        {
            if(ptr->left!=NULL)
                par->left=ptr->left;
            else
                par->left=ptr->right;
        }
        else
        {
            if(ptr->left!=NULL)
                par->right=ptr->left;
            else
                par->right=ptr->right;
        }
        delete ptr;

    }
    int del_twonodes(BST *ptr,BST *save)
    {
        struct BST *temp=ptr->right;
        while(temp->left!=NULL)
        {
            save=temp;
            temp=temp->left;
        }
        int x=temp->info;
        if(temp->left==NULL && temp->right==NULL)
        {
            del_leafnode(temp,save);
        }
        else
        {
            del_singlenode(temp,save);
        }

        return x;
    }
    void delete1()
    {
        int num,flag=0;
        cout<<"enter the number you want to delete"<<endl;
        cin>>num;
        struct BST *parent=NULL;
        check=root;
        while(1)
        {
            if(check->info==num)
                break;
            else if(check->info<num && check->right!=NULL)
            {
                parent=check;
                check=check->right;
            }
            else if(check->info>num && check->left!=NULL)
            {
                parent=check;
                check=check->left;
            }
            else
            {
                cout<<"NUMBER NOT FOUND"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(check->left==NULL && check->right==NULL)
                del_leafnode(check,parent);
            else if(check->left!=NULL && check->right!=NULL)
            {
                parent=check;
                int a=del_twonodes(check,parent);
                check->info=a;
            }
            else if(check->left==NULL || check->right==NULL)
                del_singlenode(check,parent);
        }
    }
    void preorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        cout<<a->info<<endl;
        preorder_display(a->left);
        preorder_display(a->right);
    }
}
void postorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        postorder_display(a->left);
        postorder_display(a->right);
        cout<<a->info<<endl;
    }
}
void inorder_display(BST *a)
{
    if(a==NULL)
        return;
    else{
        inorder_display(a->left);
        cout<<a->info<<endl;
        inorder_display(a->right);
    }
}

};
int main()
{
    tree ob;
    int ch;
    cout<<"Press 1 to create binary tree"<<endl<<"Press 2 to delete a node"<<"Press 3 to display"<<endl;
    cout<<"Press 0 to exit"<<endl;
    cin>>ch;
    while(ch!=0)
    {
    switch(ch)
    {
   case 1:
    ob.create();
    break;
   case 2:
    ob.delete1();
    break;
   case 3:
       char op;
       cout<<"Press 'a' to display INORDER"<<endl<<"Press 'b' to display PREORDER"<<endl;
       cout<<"Press 'c' to display POSTORDER"<<endl;
       cin>>op;
       if(op=='a')
       ob.inorder_display(ob.get());
       else if(op=='b')
        ob.preorder_display(ob.get());
       else if(op=='c')
        ob.postorder_display(ob.get());
     break;
    }
    cout<<"Press 1 to create binary tree"<<endl<<"Press 2 to delete a node"<<endl;
    cout<<"Press 4 to display"<<endl<<"Press 0 to exit"<<endl;
    cin>>ch;
    }
}


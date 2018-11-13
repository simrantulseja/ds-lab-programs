using namespace std;
#include<iostream>
class ddl
{
struct node
{
int value;
struct node *prev;
struct node *next;
};
struct node *start;
struct node *tail;
struct node *ptr;
struct node *new_node;
public:
ddl()
{
start=NULL;
}
void create_beg()
{
    int num;
    cout<<"enter the values of list"<<endl<<"Press 0 to exit"<<endl;
    cin>>num;
    while(num != 0)
    {
    if(start==NULL)
    {
        new_node=new node;
        new_node -> value=num;
        new_node -> prev=NULL;
        new_node -> next=NULL;
        start=new_node;
    }
    else
    {
        new_node=new node;
        new_node -> value=num;
        new_node -> prev=NULL;
        new_node -> next=start;
        start -> prev= new_node;
        start=new_node;

    }
    cin>>num;
    }
}

void display()
{

    ptr=start;
    while (ptr!=NULL)
    {
        cout<<ptr -> value;
        cout<<endl;
        ptr=ptr->next;
    }
}
void search()
{
    int num,flag=0;
    cout<<"Enter value to be searched"<<endl;
    cin>>num;
    ptr=start;
    while (ptr!=NULL)
    {
        if(ptr->value==num)
        {
            cout<<"Number found"<<endl;
            flag=1;
            break;
        }

      ptr=ptr->next;
    }
    if(flag==0)
        cout<<"Number not found"<<endl;
}
void create_end()
{
  int num;
    cout<<"Enter values of list"<<endl<<"Press 0 to exit"<<endl;
    cin>>num;
    while(num != 0)
    {
        if (start==NULL)
        {
             new_node=new node;
        new_node -> value=num;
        new_node -> prev=NULL;
        new_node -> next=NULL;
        start=new_node;
        tail=new_node;
        }
        else
        {
             new_node=new node;
        new_node -> value=num;
        new_node -> prev=tail;
        new_node -> next=NULL;
        tail -> next = new_node;
        tail = new_node;
        }

    cin>>num;
    }
}
void insert_beg(int num)
{
    new_node=new node;
    new_node ->value=num;
    new_node -> prev=NULL;
    new_node -> next=start;
    start -> prev=new_node;
    start=new_node;
}
void insert_end(int num)
{
    tail=start;
    while (tail->next != NULL)
    {
        tail=tail->next;
    }
     new_node=new node;
    new_node ->value=num;
    new_node -> prev=tail;
    new_node -> next=NULL;
    tail -> next=new_node;
    tail=new_node;
}
void insert_after(int num,int data)
{
    ptr=start;
    while(ptr!=NULL)
    {
        if (ptr -> value==num)
        {
            break;

        }
         ptr=ptr -> next;
    }
    if (ptr -> next==NULL)
        insert_end(data);
    else
    {
     new_node=new node;
    new_node ->value=data;
    new_node -> prev=ptr;
    new_node -> next=ptr -> next;
    new_node -> next -> prev=new_node;
    ptr -> next=new_node;
    }
}
void insert_before(int num,int data)
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        if (ptr -> value==num)
        {
            break;
        }
         ptr=ptr -> next;
    }
    if (ptr -> prev==NULL)
    {
        insert_beg(data);
    }
    else
    {
    new_node=new node;
    new_node -> value=data;
    new_node -> next=ptr;
    new_node -> prev=ptr -> prev;
    ptr -> prev -> next=new_node;
    ptr -> prev = new_node;
    }
}
void del_beg()
{
    ptr=start;
    if (ptr -> next==NULL)
    {
        start=NULL;
        delete ptr;
    }
    else
    {
    start=ptr -> next;
     ptr -> next -> prev=NULL;
    ptr -> next=NULL;
   delete ptr;
    }
}
void del_end()
{
    tail=start;
    while (tail->next != NULL)
    {
        tail=tail->next;
    }
    ptr=tail;
    if (tail->prev==NULL)
        start=NULL;
    else{
    ptr -> prev->next=NULL;
    tail=ptr->prev;
    ptr->prev=NULL;
    }
    delete ptr;
}
void del_given(int num)
{
    ptr=start;
    while (ptr != NULL)
    {
        if (ptr->value==num)
        {
            break;
        }
            ptr=ptr->next;

    }
    if (ptr->next==NULL)
    {
        del_end();
    }
    else if (ptr->prev==NULL)
    {
        del_beg();
    }
    else{
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        ptr->prev=NULL;
        ptr->next=NULL;
        delete ptr;
    }
}
};
int main()
{
    ddl obj;
    int ch;
    obj.create_end();
    cout<<"Press 1 to insert a new element in beginning"<<endl;
    cout<<"Press 2 to insert a new element at end"<<endl<<"Press 3 to insert new element after a given element"<<endl;
    cout<<"Press 4 to insert a new element before a given element"<<endl<<"Press 5 to delete an element"<<endl;
    cout<<"Press 6 to search an element"<<endl<<"Press 7 to display list"<<endl<<"Press 0 to exit"<<endl;
    cin>>ch;
    while (ch != 0)
    {
        switch(ch)
        {
        case 1:
            int num1;
            cout<<"enter value to be inserted"<<endl;
            cin>>num1;
            obj.insert_beg(num1);
            break;
        case 2:
            int num2;
            cout<<"enter value to be inserted"<<endl;
            cin>>num2;
            obj.insert_end(num2);
            break;
        case 3:
            int num3,num4;
            cout<<"enter value to be inserted"<<endl;
            cin>>num3;
            cout<<"enter the value after which it has to be inserted"<<endl;
            cin>>num4;
            obj.insert_after(num4,num3);
            break;
        case 4:
            int num5,num6;
            cout<<"enter value to be inserted"<<endl;
            cin>>num5;
            cout<<"enter the value before which it has to be inserted"<<endl;
            cin>>num6;
            obj.insert_before(num6,num5);
            break;
        case 5:
            char j;
            cout<<"press f to delete first element"<<endl<<"press l to delete last element"<<endl<<"press s to delete a specific element"<<endl;
            cin>>j;
            if(j=='f')
                obj.del_beg();
            else if(j=='l')
                obj.del_end();
            else if(j=='s')
            {
                int num;
                cout<<"enter the number you want to delete"<<endl;
                cin>>num;
                obj.del_given(num);
            }
            break;
        case 6:
            obj.search();
            break;
        case 7:
            obj.display();
            break;
        }
         cout<<"Press 1 to insert a new element in beginning"<<endl;
    cout<<"Press 2 to insert a new element at end"<<endl<<"Press 3 to insert new element after a given element"<<endl;
    cout<<"Press 4 to insert a new element before a given element"<<endl<<"Press 5 to delete an element"<<endl;
    cout<<"Press 6 to search an element"<<endl<<"Press 7 to display list"<<endl<<"Press 0 to exit"<<endl;
         cin>>ch;
    }
}

using namespace std;
#include<iostream>
class stacks
{
    int *arr;
    int top;
    int size1;
public:
    stacks(int n)
    {
        top=-1;
        size1=n;
        arr=new int[size1];
    }
    void push()
    {
         int item;
        if (top==size1-1)
            cout<<"overflow"<<endl;
        else
        {
            cout<<"enter the value to be inserted"<<endl;
            cin>>item;
            top++;
            arr[top]=item;
        }
    }
    void pop()
    {
        if (top==-1)
            cout<<"underflow"<<endl;
        else
        {
            cout<<"element deleted:"<<arr[top]<<endl;
            top--;
        }
    }
    void display()
    {
        while(top!=-1)
        {
            pop();
        }
    }
};
int main()
{
    int ch,s;
    cout<<"enter size of stack"<<endl;
    cin>>s;
    stacks ob(s);
    cout<<"Press 1 to push an element"<<endl<<"Press 2 to pop an element"<<endl<<"Press 3 to display"<<endl<<"Press 0 to exit"<<endl;
    cin>>ch;
    while (ch!=0)
    {
        switch(ch)
        {
        case 1:
            ob.push();
            break;
        case 2:
            ob.pop();
            break;
        case 3:
            ob.display();
            break;
        }
        cout<<"Press 1 to push an element"<<endl<<"Press 2 to pop an element"<<endl<<"Press 3 to display"<<endl<<"Press 0 to exit"<<endl;
        cin>>ch;
    }
}


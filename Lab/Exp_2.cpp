using namespace std;
#include<iostream>
class array1
{
int *arr,n;
public:
array1 (int size_)
{
n=size_;
arr=new int[n];
}
void input()
{
    cout<<"Enter values"<<endl;
for (int i=0;i<n;i++)
{
cin>>arr[i];
}
}
void display()
{
for (int i=0;i<n;i++)
{
cout<<arr[i]<<endl;
}
}
void lsearch()
{
int flag=0,value;
cout<<"enter value to be searched"<<endl;
cin>>value;
for (int i=0;i<n;i++)
{
if (arr[i]==value)
{
flag=1;
cout<<"FOUND"<<endl;
break;
}
}
if (flag==0)
{
cout<<"NOT FOUND"<<endl;
}
}

};

int main()
{
int size_,ch;
cout<<"enter number of elements"<<endl;
cin>>size_;
array1 ob(size_);
ob.input();
cout<<"Press 1 to search a number"<<endl<<"Press 2 to display array"<<endl<<"0 to exit"<<endl;
cin>>ch;
while (ch!=0)
{
switch(ch)
{
case 1:
    ob.lsearch();
    break;
case 2:
   ob.display();
   break;
}
cout<<"Press 1 to search a number"<<endl<<"Press 2 to display array"<<endl<<"0 to exit"<<endl;
cin>>ch;
}
}

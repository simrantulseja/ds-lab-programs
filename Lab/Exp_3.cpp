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
    cout<<"enter values"<<endl;
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

void bsearch()
{
    int value,mid,beg,end_,flag=0;
    cout<<"enter item to be searched";
    cin>>value;
    beg=0;
    end_=n-1;
    mid= (beg+end_)/2;
    while (beg<=end_)
    {
    if (arr[mid]==value)
    {
        cout<<"Number found"<<endl;
        flag=1;
        break;
    }
    else
    {
        if (arr[mid]>value)
            end_=mid-1;
        else
            beg=mid+1;

    }
    mid= (beg+end_)/2;
}
if (flag==0)
    cout<<"Number not found"<<endl;
}
void bsort();
};
void array1::bsort()
{ int temp,flag;
    for (int p=1;p<n;p++)
    {
        flag=0;
        for (int c=0;c<n-p;c++)
        {
            if (arr[c]>arr[c+1])
            { flag=1;
                temp=arr[c];
                arr[c]=arr[c+1];
                arr[c+1]=temp;
            }
        }
        if (flag==0)
            break;
    }
}

int main()
{
int size_,ch;
cout<<"enter size of array"<<endl;
cin>>size_;
array1 ob(size_);
ob.input();
ob.bsort();
cout<<"Sorted Array[BUBBLE SORT]:"<<endl;
ob.display();
cout<<"Press 1 to search an element[BINARY SEARCH]"<<endl<<"Press 0 to exit"<<endl;
cin>>ch;
while (ch!=0)
{
  if(ch==1)
    ob.bsearch();
cout<<"Press 1 to search an element[BINARY SEARCH]"<<endl<<"Press 0 to exit"<<endl;
cin>>ch;
}
}

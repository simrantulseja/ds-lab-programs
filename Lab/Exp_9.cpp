#include<iostream>
using namespace std;

class quick_sort
{

public:
void qs(int *arr,int p,int r)
{
int q;
if(p<r)
{
    q=sort_pivot(arr,p,r);
    qs(arr,p,q-1);
    qs(arr,q+1,r);
}
}
int  sort_pivot(int *arr,int p,int r)
{
    int pivot=arr[r];
    int temp;
    int  j=p-1;
        for(int i=p;i<r;i++)
        {
            if(arr[i]<=pivot)
            {
                j++;

                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[j+1];
        arr[j+1]=arr[r];
        arr[r]=temp;
        return(j+1);
    }
};

int main()
{

    quick_sort obj;
    int size_,*arr;
    cout<<"Enter the size of the array: ";
    cin>>size_;
    arr=new int[size_];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<size_;i++)
        cin>>arr[i];
    obj.qs(arr,0,size_-1);
    cout<<"Elements of the array: "<<endl;
    for(int j=0;j<size_;j++)
        cout<<arr[j]<<" ";
    return 0;
}

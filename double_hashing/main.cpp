#include<iostream>
using namespace std;

int Hash1(int x)
{
    return x%10;
}

int Hash2(int x)
{
    return 7-(x%7);
}

void Insert(int x,int H[])
{
    int index=Hash1(x);
    if(H[index]==-1)
        H[index]=x;
    else
    {
        int in2=Hash2(x);
        for(int i=0;i<=9;i++)
        {
            int ind=((index+(i*in2))%10);
            if(H[ind]==-1)
            {
                H[ind]=x;
                break;
            }
        }
    }
}

int Search(int H[],int key)
{
    int index1,index2,index;
    index1=Hash1(key);
    if(H[index1]==key)
        return 1;
    else
    {
        index2=Hash2(key);
        for(int i=0;i<10;i++)
        {
            index=((index1+(i*index2))%10);
            if(H[index]==key)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    cout<<"Enter the number of elements to be entered in the array : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements to be entered in the Array : "<<endl;
    int A[10];
    int H[10];
    for(int i=0;i<10;i++)
        H[i]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        Insert(A[i],H);
    }
    cout<<"Enter the element to be seached in the array of elements that have been entered : "<<endl;
    int s;
    cin>>s;
    int b=Search(H,s);
    if(b)
        cout<<"The element "<<s<<" is present in the array entered "<<endl;
    else
        cout<<"The element "<<s<<" is not present in the array entered "<<endl;
    return 0;
}

#include <iostream>
using namespace std;
void display(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<endl;
    }
}
void Selection(int ar[], int n)
{   int min=0,temp=0;
    for( int i=0;i<n;i++)
    {
      min=i;
      for(int j=i+1;j<n;j++)
        {
         if(ar[j]<ar[min])
            {
              min=j;
                }
                 }
    temp=ar[i];
    ar[i]=ar[min];
    ar[min]=temp;
    }
}
void Bubble(int ar[], int n)
{   int temp=0;
    for( int i=1;i<n;i++)
    {
      for(int j=0;j<n-1;j++)
        {
         if(ar[j]>ar[j+1])
         {
              temp=ar[j];
              ar[j]=ar[j+1];
              ar[j+1]=temp;
         }}}}
void Insertion(int ar[], int n)
{   int key=0;
    for( int i=1;i<n;i++)
    {
      key=ar[i];
      int j=i-1;
      while(j>=0&& key<ar[j]){
          ar[j+1]=ar[j];
          j--;
      }
    ar[j+1]=key;
}}
int main()
{
    char ch='y';
    do{
        cout<<"\n Hi! welcome do you want to continue (Y/N):"<<endl;
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            int i,m,n;
            cout<<"\n Enter your choice: \n 1.Selection sort\n 2.Bubble sort\n 3.Insertion sort"<<endl;
            cin>>m;
            cout<<"\n Enter the size of the array:"<<endl;
            cin>>n;
            int ar[n];
            cout<<"\n Enter the elements:"<<endl;
            for( i=0;i<n;i++)
            {
                cin>>ar[i];
            }
            switch(m)
            {
                case 1:
                    Selection(ar,n);
                    cout<<"\n Sorted array after Selection sort is:"<<endl;
                    display(ar,n);
                    break;
                case 2:
                    Bubble(ar,n);
                    cout<<"\n Sorted array after Bubble sort is:"<<endl;
                    display(ar,n);
                    break;
                case 3:
                    Insertion(ar,n);
                    cout<<"\n Sorted array after Insertion sort is:"<<endl;
                    display(ar,n);
                    break;
                default:
                cout<<"invalid choice";
            }
        }
        else{
            cout<<"\n Thank you program terminated";
        }
    }while(ch=='Y'||ch=='y');

    return 0;
}

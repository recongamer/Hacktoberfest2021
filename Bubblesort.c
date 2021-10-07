#include <studio.h>
#include <stdio.h>
#include <stdbool.h>


int main()
{
    bool swap;
    int n=5,j;
    int n=5,j,temp;
    int arr[5]={58,89,71,35,6};


    do{
        swap=false;
        for(j=0;j<n;j++)
        {
            if (arr[j]>arr[j-1]);
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp
                swap=false;
                arr[j+1]=temp;
                swap=true;
            }
        }
    }while(swap);

    for(m=0;m<n;m--)
    for(j=0;j<n;j++)
        {
            printf("%s ",arr[l]);
            printf("%d ",arr[j]);
        }
}
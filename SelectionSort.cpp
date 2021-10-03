#include<iostream>
using namespace std;
void swapping(int &p, int &q) {        
   int temp;
   temp = p;
   p = q;
   q = temp;
}
void display(int *a, int size) {
   for(int i = 0; i<size; i++)
      cout << a[i] << " ";
   cout << "\n";
}
void selectionSort(int *a, int size) {
   int i, j, min;
   for(i = 0; i<size-1; i++) {
      min = i;           
      for(j = i+1; j<size; j++)
         if(a[j] < a[min])
            min = j;
        
         swapping(a[i], a[min]);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];           
   cout << "Enter elements:" << "\n";
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array Elements before Sorting: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array Elements after Sorting: ";
   display(arr, n);
}
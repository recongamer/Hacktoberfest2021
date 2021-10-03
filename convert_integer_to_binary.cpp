#include<iostream>
using namespace std;

// function to convert given number into binary
// Time complexictiy for below function will be: O(log(number))
int ConvertToBinary(int number)
{
   int binary = 0 , i=1;

   while(number)
   {
      int rem = number % 2;
      binary = binary + rem*i;
      i = i*10;
      number = number/2;
   }
   return binary;
}

int main()
{
   int number = 17; // can give any input using cin 

   int binary = ConvertToBinary(number);
   cout<<"Converted Binary is: "<<binary<<endl;
   return 0;
}

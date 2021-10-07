#include <iostream>
using namespace std;
 void pascaltri(int n){
     for(int line=1;line<=n;line++){
     int c=1;    
        for(int i=1;i<=line;i++){
             
             cout<<c<<' ';
             c = c*(line-i)/i;
         }
         cout<<"\n";
     }
 }
 
 int main(){
     int n=5;
     pascaltri(n);
     return 0;
 }

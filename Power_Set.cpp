// modified power set
#include<iostream>
#include<math.h>
using namespace std;
int main() {
    cout << "Enter the number" << endl;
    int n;
    cin >> n;
    cout << "Enter a string" << endl;
    string s;
    cin >> s;
    cout << "Output is : " << endl;
    int m=pow(2,n);
    for(int i=1;i<m;i++) {
        string c=" ";
        int j=0;
        int x=i;
        while(x) {
            if(x&1) {
                c=c+s[j];    
            }
            j++;
            x=x>>1;    
        }
           cout << c  << " ";
    }
    cout << "{}" << endl;
}
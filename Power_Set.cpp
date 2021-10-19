//Author - Sanskar Modi
//Lang - C++
//Git-Hub id - https://github.com/SanskarModi22
#include <bits/stdc++.h>
using namespace std;

void Power(string S)
{
    int n = S.length();

    int total_comb = pow(2, n);
    for (int counter = 0; counter < total_comb; counter++)
    {
        string str="";
        
        for (int k = 0; k < n; k++)
        {
            if (((1 << k) & counter) != 0)
            {
               str+=S[k]; 
            }
        }
        cout <<str<< endl;
    }
}
int main()
{
    cout << "Input the String for finding the power set" << endl;
    string set;
    cin >> set;
    Power(set);
}
#include <bits/stdc++.h>

using namespace std;

string timeInWords(int h, int m) {
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine" };
    
 string time;
 
 if(m<=30){
    if(m==0)
    time=v[h]+" o' clock";
    else if(m==15)
    time="quarter past "+v[h];
    else if(m==30)
    time="half past "+v[h];
    else if(m==1)
    time=v[m]+" minute past "+v[h];
    else
    time=v[m]+" minutes past "+v[h];
  }
  else{
    if(m==45)
    time="quarter to "+v[h+1];
    else if(m==59)
    time=v[60-m]+" minute to "+v[h+1];
    else
    time=v[60-m]+" minutes to "+v[h+1];
 }
 return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

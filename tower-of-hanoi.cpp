//tower of hanoi


#include <bits/stdc++.h>
using namespace std;

void towerofHanoi(int n, char fr,char tr, char ar)
{
	if (n == 1)
	{
	cout << "Move disk 1 from rod " << fr <<" to rod " << tr<<endl;
		return;
	}
	towerofHanoi(n - 1, fr, ar, tr);
	cout << "Move disk " << n << " from rod " << fr <<" to rod " << tr << endl;
	towerofHanoi(n - 1, ar, tr, fr);
}

int main()
{
	int n ;
	cin>>n;
	towerofHanoi(n, 'A', 'C', 'B'); 
	return 0;
}

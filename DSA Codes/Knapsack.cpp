#include <bits/stdc++.h>
#include<math.h>
using namespace std;


int knapSack(int capacity, int wt[], int v[], int n)
{

	// Base Case
	if (n == 0 || capacity == 0)
		return 0;

	// If weight of the nth item is more
	// than Knapsack capacity capacity, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > capacity)
		return knapSack(capacity, wt, v, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(
			v[n - 1]
				+ knapSack(capacity - wt[n - 1],
						wt, v, n - 1),
			knapSack(capacity, wt, v, n - 1));
}


int main()
{
	int v[] = { 5, 100, 70 }; //value
	int wt[] = { 12, 67, 23 }; //weights
	int capacity = 50;
	int n = sizeof(v) / sizeof(v[0]);
	cout << knapSack(capacity, wt, v, n);
	return 0;
}

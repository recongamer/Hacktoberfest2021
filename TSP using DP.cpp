#include <bits/stdc++.h>
using namespace std;
int main()
{
	int graph[][4] = { { 0, 100, 150, 200 },
					   { 100, 0, 350, 250 },
					   { 150, 350, 0, 300 },
					   { 200, 250, 300, 0 } };
	int s = 0, min_path = INT_MAX;;
	vector<int> vertex;
	for (int i = 0; i < 4; i++)
		if (i != s)
			vertex.push_back(i);
			
	while (next_permutation(vertex.begin(), vertex.end())) 
	{
		int current_pathweight = 0, k = s;
		for (int i = 0; i < vertex.size(); i++) 
		{
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		min_path = min(min_path, (current_pathweight += graph[k][s]));
	} 
	cout <<" Min Path Distance : " <<min_path << endl;
	return 0;
}


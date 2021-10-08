/*
 * Author: andreibogdanflorea
 *
 * This program solves the Range Minimum Query problem by using the Sparse Table
 * data structure, computing the answer to each query in O(1) time
 *
 * Drawback: the initial array cannot change throughout the execution of the
 * program
 */

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define K 26

// sparseTable[i][j] stores the minimum value for the range [i, i + 2^j - 1]

vector<int> precompute_log(int n)
{
    vector<int> computed_log(n + 1);
    computed_log[1] = 0;
    for (int i = 2; i <= n; i++)
        computed_log[i] = computed_log[i / 2] + 1;

    return computed_log;
}

void sparseTable_RMQ(vector<int> array, int n, vector<pair<int, int>> queries, int m)
{
    int sparse_table[MAXN][K];
    vector<int> computed_log = precompute_log(n);

    for (int i = 0; i < n; i++)
        sparse_table[i][0] = array[i];

    for (int j = 1; j < K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            sparse_table[i][j] = min(sparse_table[i][j-1],
                                     sparse_table[i + (1 << (j - 1))][j - 1]);

    for (auto &query: queries) {
        int left = query.first, right = query.second;
        int j = computed_log[right - left + 1];
        int minimum = min(sparse_table[left][j], sparse_table[right - (1 << j) + 1][j]);
        cout << minimum << '\n';
    }
}

int main()
{
	int n, m, x;
    cin >> n >> m;

    vector<int> v(n);
    vector< pair<int, int> > queries(m);

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        queries[i] = make_pair(l, r);
    }

    sparseTable_RMQ(v, n, queries, m);

	return 0;
}

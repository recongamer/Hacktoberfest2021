// C++ implementation to find shortest string for
// a combination of two strings
#include <bits/stdc++.h>
using namespace std;
 
// Vector that store the index of string a and b
vector<int> index_a;
vector<int> index_b;
 
// Subroutine to Backtrack the dp matrix to
// find the index vector traversing which would
// yield the shortest possible combination
void index(int dp[][100], string a, string b,
           int size_a, int size_b)
{
    // Clear the index vectors
    index_a.clear();
    index_b.clear();
 
    // Return if either of a or b is reduced
    // to 0
    if (size_a == 0 || size_b == 0)
        return;
 
    // Push both to index_a and index_b with
    // the respective a and b index
    if (a[size_a - 1] == b[size_b - 1]) {
        index(dp, a, b, size_a - 1, size_b - 1);
        index_a.push_back(size_a - 1);
        index_b.push_back(size_b - 1);
    } else {
        if (dp[size_a - 1][size_b] > dp[size_a]
                                    [size_b - 1]) {
            index(dp, a, b, size_a - 1, size_b);
        } else {
            index(dp, a, b, size_a, size_b - 1);
        }
    }
}
 
// function to combine the strings to form
// the shortest string
void combine(string a, string b, int size_a,
             int size_b)
{
 
    int dp[100][100];
    string ans = "";
    int k = 0;
 
    // Initialize the matrix to 0
    memset(dp, 0, sizeof(dp));
 
    // Store the increment of diagonally
    // previous value if a[i-1] and b[j-1] are
    // equal, else store the max of dp[i][j-1]
    // and dp[i-1][j]
    for (int i = 1; i <= size_a; i++) {
        for (int j = 1; j <= size_b; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1],
                               dp[i - 1][j]);
            }
        }
    }
 
    // Get the Lowest Common Subsequence
    int lcs = dp[size_a][size_b];
 
    // Backtrack the dp array to get the index
    // vectors of two strings, used to find
    // the shortest possible combination.
    index(dp, a, b, size_a, size_b);
 
    int i, j = i = k;
 
    // Build the string combination using the
    // index found by backtracking
    while (k < lcs) {
        while (i < size_a && i < index_a[k]) {
            ans += a[i++];
        }
 
        while (j < size_b && j < index_b[k]) {
            ans += b[j++];
        }
 
        ans = ans + a[index_a[k]];
        k++;
        i++;
        j++;
    }
 
    // Append the remaining characters in a
    // to answer
    while (i < size_a) {
        ans += a[i++];
    }
 
    // Append the remaining characters in b
    // to answer
    while (j < size_b) {
        ans += b[j++];
    }
 
    cout << ans;
}
 
// Driver code
int main()
{
    string a = "algorithm";
    string b = "rhythm";
 
    // Store the length of string
    int size_a = a.size();
    int size_b = b.size();
 
    combine(a, b, size_a, size_b);
    return 0;
}

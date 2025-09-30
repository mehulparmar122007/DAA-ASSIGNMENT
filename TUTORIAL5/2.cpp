#include <bits/stdc++.h>
using namespace std;

// int maxl(int n, vector<int>& p, int j, vector<int>& v, vector<vector<int>>& dp) {
//     // Base case: only length v[0] = 1 is allowed
//     if (j == 0) {
//         return p[0] * n; // cut all into 1-length pieces
//     }
//     if(n==0)return 0;

//     if (dp[j][n] != -1) return dp[j][n];

//     // Not pick current length
//     int notpick = maxl(n, p, j - 1, v, dp);

//     // Pick current length (if possible)
//     int pick = INT_MIN;
//     if (n >= v[j]) {
//         pick = p[j] + maxl(n - v[j], p, j, v, dp);
//     }

//     return dp[j][n] = max(pick, notpick);
// }

int main() {
    int n;
    cout << "Enter length of rod: ";
    cin >> n;

    vector<int> p(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) cin >> p[i];


    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // cout << "Maximum Profit = " << maxl(n, p, n - 1, v, dp) << endl;
    for(int i=0;i<n+1;i++)
    {
        dp[0][i] = p[0]*i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            int notpick = dp[i-1][j];
            int pick = 0;
            if(i+1<=j)
            {
                pick = p[i] + dp[i][j-v[i]];
            }
            dp[i][j] = max(pick , notpick);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}

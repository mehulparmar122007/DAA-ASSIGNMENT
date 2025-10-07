#include <bits/stdc++.h>
#include <vector>

using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    // base cases
    for (int i = 1; i <= eggs; i++) dp[i][0] = 0; // 0 floor
    for (int i = 1; i <= eggs; i++) dp[i][1] = 1; // 1 floor
    for (int j = 1; j <= floors; j++) dp[1][j] = j; // 1 egg

    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            dp[e][f] = INT_MAX;
            for (int x = 1; x <= f; x++) {
                int attempts = 1 + max(dp[e-1][x-1], dp[e][f-x]);
                if (attempts < dp[e][f]) dp[e][f] = attempts;
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;
    cout << "enter number of eggs: ";
    cin >> eggs;
    cout << "enter number of floors: ";
    cin >> floors;

    int minAttempts = eggDrop(eggs, floors);
    cout << "minimum number of attempts: " << minAttempts << endl;

    return 0;
}

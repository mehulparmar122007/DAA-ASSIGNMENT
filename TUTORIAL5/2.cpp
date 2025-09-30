#include <bits/stdc++.h>
using namespace std;
int minop(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 0 + minop(i - 1, j - 1, s1, s2, dp);
    }
    else
    {
        return dp[i][j] = min(1 + minop(i, j - 1, s1, s2, dp), min(1 + minop(i - 1, j, s1, s2, dp), 1 + minop(i - 1, j - 1, s1, s2, dp)));
    }
}
int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    //  cout<<"min number of op is :"<<minop(s1.length()-1 , s2.length()-1 , s1,s2,dp)<<endl;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(1 + dp[i][j - 1], min(1 + dp[i-1][j], 1 + dp[i-1][j-1]));
            }
        }
    }
    cout<<"min number of operation is  : "<<dp[n][m]<<endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
           cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}
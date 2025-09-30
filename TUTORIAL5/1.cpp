#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter orders of matrix : ";
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
    }
    vector<vector<int>> m(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                m[i][j] = 0;
            }
        }
    }
    for (int l = 1; l <= n - 1; l++)
    {
        for (int i = 1; i < n - l; i++)
        {
            int j = l + i;
            for (int k = i; k < j; k++)
            {
                int M = m[i][k] + m[k + 1][j] + order[i - 1] * order[j] * order[k];
                m[i][j] = min(M, m[i][j]);
            }
        }
    }
    cout << m[1][n - 1] << endl;
}
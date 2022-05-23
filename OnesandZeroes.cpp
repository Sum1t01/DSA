#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> dp;

int max_subset_01(vector<string> &strs, int i0, int i1, int n)
{
    if (i0 == 0 && i1 == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 0;
    }
    int count0 = count(strs[n - 1].begin(), strs[n - 1].end(), '0');
    int count1 = count(strs[n - 1].begin(), strs[n - 1].end(), '1');

    if (count0 > i0 || count1 > i1)
    {
        return max_subset_01(strs, i0, i1, n - 1);
    }

    return max(max_subset_01(strs, i0, i1, n - 1), 1 + max_subset_01(strs, i0 - count0, i1 - count1, n - 1));
    return 0;
}

int max_subset_01_memoization(vector<string> &strs, int i0, int i1, int n)
{
    if (i0 == 0 && i1 == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][i0][i1] != -1)
    {
        return dp[n][i0][i1];
    }
    int count0 = count(strs[n - 1].begin(), strs[n - 1].end(), '0');
    int count1 = count(strs[n - 1].begin(), strs[n - 1].end(), '1');

    if (count0 > i0 || count1 > i1)
    {
        return dp[n][i0][i1] = max_subset_01_memoization(strs, i0, i1, n - 1);
    }
    return dp[n][i0][i1] = max(max_subset_01_memoization(strs, i0, i1, n - 1), 1 + max_subset_01_memoization(strs, i0 - count0, i1 - count1, n - 1));
}

int max_subset_01_bottomup(vector<string> &strs, int i0, int i1, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i0; j++)
        {
            for (int k = 0; k <= i1; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i0; j++)
        {
            for (int k = 1; k <= i1; k++)
            {
                int count0 = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
                int count1 = count(strs[i - 1].begin(), strs[i - 1].end(), '1');

                if (count0 > j || count1 > k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - count0][k - count1]);
                }
            }
        }
    }

    return dp[n][i0][i1];
}

int main()
{
    vector<string> strs = {"10", "0", "1"};
    int m = 1, n = 1;
    // cout<<count(strs[2].begin(),strs[2].end(),'1');
    dp.resize(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    cout << max_subset_01_bottomup(strs, m, n, strs.size());
}
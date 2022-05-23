#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

bool subsetSum(vector<int> &subset, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return sum == 0;
    }

    if (subset[n - 1] > sum)
    {
        return subsetSum(subset, sum, n - 1);
    }
    return subsetSum(subset, sum, n - 1) || subsetSum(subset, sum - subset[n - 1], n - 1);
}

bool subsetSum_memoization(vector<int> &subset, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return sum == 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (subset[n - 1] > sum)
    {
        return dp[n][sum] = subsetSum_memoization(subset, sum, n - 1);
    }
    return dp[n][sum] = subsetSum_memoization(subset, sum, n - 1) || subsetSum_memoization(subset, sum - subset[n - 1], n - 1);
}

bool subsetSum_bottomup(vector<int> &subset, int sum, int n)
{
    for (int i = 0; i <= subset.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = (j == 0) ? true : false;
            }
        }
    }

    for (int i = 1; i <= subset.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (subset[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - subset[i - 1]];
            }
        }
    }
    return dp[subset.size()][sum];
}

int main()
{
    vector<int> subset = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    dp.resize(subset.size() + 1, vector<int>(sum + 1, -1));
    cout << subsetSum_bottomup(subset, sum, subset.size());
}
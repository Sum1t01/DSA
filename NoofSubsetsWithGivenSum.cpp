#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int no_of_subset_sum(vector<int> &nums, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    if (nums[n - 1] > sum)
    {
        return no_of_subset_sum(nums, sum, n - 1);
    }
    return no_of_subset_sum(nums, sum, n - 1) + no_of_subset_sum(nums, sum - nums[n - 1], n - 1);
}

int no_of_subset_sum_memoization(vector<int> &nums, int sum, int n)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (nums[n - 1] > sum)
    {
        return dp[n][sum] = no_of_subset_sum_memoization(nums, sum, n - 1);
    }
    return dp[n][sum] = no_of_subset_sum_memoization(nums, sum, n - 1) + no_of_subset_sum_memoization(nums, sum - nums[n - 1], n - 1);
}

int no_of_subset_sum_bottomup(vector<int> &nums, int sum, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = (j == 0) ? 1 : 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    dp.resize(nums.size() + 1, vector<int>(sum + 1, -1));
    cout << no_of_subset_sum_bottomup(nums, sum, nums.size());
}
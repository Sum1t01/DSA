#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
int knapsack_bounded(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (weight[n - 1] > capacity)
    {
        return knapsack_bounded(weight, profit, capacity, n - 1);
    }
    return max(knapsack_bounded(weight, profit, capacity, n - 1), profit[n - 1] + knapsack_bounded(weight, profit, capacity - weight[n - 1], n - 1));
}

int knapsack_unbounded(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (weight[n - 1] > capacity)
    {
        return knapsack_unbounded(weight, profit, capacity, n - 1);
    }
    return max(knapsack_unbounded(weight, profit, capacity, n - 1), profit[n - 1] + knapsack_unbounded(weight, profit, capacity - weight[n - 1], n));
}

int knapsack_bounded_memoization(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }
    if (weight[n - 1] > capacity)
    {
        return dp[n][capacity] = knapsack_bounded_memoization(weight, profit, capacity, n - 1);
    }
    return dp[n][capacity] = max(knapsack_bounded(weight, profit, capacity, n - 1), profit[n - 1] + knapsack_bounded(weight, profit, capacity - weight[n - 1], n - 1));
}

int knapsack_unbounded_memoization(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }

    if (weight[n - 1] > capacity)
    {
        return dp[n][capacity] = knapsack_unbounded_memoization(weight, profit, capacity, n - 1);
    }

    return dp[n][capacity] = max(knapsack_unbounded_memoization(weight, profit, capacity, n - 1), profit[n - 1] + knapsack_unbounded_memoization(weight, profit, capacity - weight[n - 1], n));
}

int knapsack_bounded_bottomup(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    for (int i = 0; i <= weight.size(); i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= weight.size(); i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weight[i - 1] > capacity)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }
    return dp[weight.size()][capacity];
}

int knapsack_unbounded_bottomup(vector<int> &weight, vector<int> &profit, int capacity, int n)
{
    for (int i = 0; i <= weight.size(); i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= weight.size(); i++)
    {
        for (int j = 1; j <=capacity; j++)
        {
            if (weight[i - 1] > capacity)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i][j - weight[i - 1]]);
            }
        }
    }
    return dp[weight.size()][capacity];
}

int main()
{
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50;
    dp.resize(weight.size() + 1, vector<int>(capacity + 1, -1));
    cout << knapsack_unbounded(weight, profit, capacity, weight.size());
    cout << knapsack_unbounded_bottomup(weight, profit, capacity, weight.size());
}
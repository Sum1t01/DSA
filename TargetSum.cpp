#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>dp;

int target_sum(vector<int> &nums, int target, int n, int sum = 0)
{
    // if (sum == target)
    // {
    //     return 1;
    // }
    if (n == 0)
    {
        return sum==target;
    }
    return target_sum(nums, target, n - 1, sum - nums[n - 1]) + target_sum(nums, target, n - 1, sum + nums[n - 1]);
}

int target_sum_memoization(vector<int> &nums, int target, int n, int sum=0)
{
    if(n==0)
    {
        return sum==0;
    }
    
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    dp.resize(nums.size()+1,vector<int>(target+1,-1));
    cout << target_sum(nums, target, nums.size());
    // this is not working at all
}
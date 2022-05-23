#include <bits/stdc++.h>

using namespace std;

int subset_sum_diff(vector<int> &nums, int sum, int n, int mindiff)
{
    if (n == 0)
    {
        return abs((mindiff-sum)-sum);
    }
    return min(subset_sum_diff(nums, sum + nums[n - 1], n - 1, mindiff), subset_sum_diff(nums, sum, n - 1, mindiff));
}

int main()
{
    vector<int> nums = {1, 6, 11, 5};
    int mindiff = accumulate(nums.begin(), nums.end(), 0);
    cout<<subset_sum_diff(nums, 0, nums.size(), mindiff);
}
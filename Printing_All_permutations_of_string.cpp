#include <bits/stdc++.h>
using namespace std;
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            //backtrack
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}
void recurPermute2(int index, vector<vector<int>> &ans, vector<int> &num)
{
    if (index == num.size())
    {
        ans.push_back(num);
        return;
    }
    for (int i = index; i < num.size(); i++)
    {
        swap(num[index], num[i]);
        recurPermute2(index + 1, ans, num);
        //backtrack
        swap(num[index], num[i]);
    }
}
vector<vector<int>> permute_2(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurPermute2(0, ans, nums);
    return ans;
}
int main()
{
    vector<int> nums = {1, 4, 6, 7};
    int n = sizeof(nums) / sizeof(int);
    vector<vector<int>> ans = permute(nums);
    for (auto u : ans)
    {
        for (auto v : u)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    vector<vector<int>> ans1 = permute_2(nums);
    for (auto u : ans1)
    {
        for (auto v : u)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
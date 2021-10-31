#include <iostream>
#include <cmath>
using namespace std;
int minNumForSum(int n, int dp[])
{
    int ans = n;
    if (sqrt(n) == (int)sqrt(n))
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    for (int i = 1; i * i <= n; i++)
    {
        int x = 1 + minNumForSum(n - i * i, dp);
        ans = min(ans, x);
    }
    dp[n] = ans;
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1]; //DOn't take n here, it will cause problem when accessing zero based indexing in dp array
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (-1);
    }
    cout << minNumForSum(n, dp);
    return 0;
}
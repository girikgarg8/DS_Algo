#include <iostream>
using namespace std;
int LCS(string s, string t)
{
    int u = s.size();
    int v = t.size();
    int dp[u + 1][v + 1];
    for (int i = 0; i <= u; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= v; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= u; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (s[u - i] == t[v - j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int a = dp[i - 1][j - 1];
                int b = dp[i - 1][j];
                int c = dp[i][j - 1];
                dp[i][j] = max(a, max(b, c));
            }
        }
    }
    return dp[u][v];
}
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << LCS(s, t);
    return 0;
}
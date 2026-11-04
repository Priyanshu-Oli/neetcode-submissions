#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dp[1001][1001];

    int solve(const string& str1, const string& str2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (str1[n - 1] == str2[m - 1]) {
            return dp[n][m] = 1 + solve(str1, str2, n - 1, m - 1);
        }

        return dp[n][m] = max(
            solve(str1, str2, n - 1, m),
            solve(str1, str2, n, m - 1)
        );
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        memset(dp, -1, sizeof(dp));

        int lcs = solve(str1, str2, n, m);

        string ans = "";
        int i = n;
        int j = m;

        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            }
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
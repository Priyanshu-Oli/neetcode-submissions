#include <cstring>
class Solution {
    int dp[1001][1001];

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        memset(dp, -1, sizeof(dp));

        return solve(text1, text2, n, m);
    }

    int solve(string text1, string text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + solve(text1, text2, n - 1, m - 1);
        }

        return dp[n][m] = max(
            solve(text1, text2, n, m - 1),
            solve(text1, text2, n - 1, m)
        );
    }
};
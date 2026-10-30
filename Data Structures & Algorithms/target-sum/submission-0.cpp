class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        int requiredSum = (totalSum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(requiredSum + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= requiredSum; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][requiredSum];
    }
};
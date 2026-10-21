
class Solution {
public:
    int solve(int i, int start, vector<int>& nums,
              vector<int>& dp) {
        if (i < start) return 0;

        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i - 2, start, nums, dp);
        int skip = solve(i - 1, start, nums, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        vector<int> dp1(n, -1);
        int case1 = solve(n - 2, 0, nums, dp1);

        // Case 2: Exclude first house
        vector<int> dp2(n, -1);
        int case2 = solve(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }
};

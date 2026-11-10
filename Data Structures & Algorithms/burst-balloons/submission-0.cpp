
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();


        vector<int> arr(n + 2, 1);

        for(int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solve(arr, 1, n, dp);
    }

    int solve(vector<int>& arr, int i, int j,
              vector<vector<int>>& dp) {

        if(i > j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for(int k = i; k <= j; k++) {

            int coins = arr[i - 1] * arr[k] * arr[j + 1]
                      + solve(arr, i, k - 1, dp)
                      + solve(arr, k + 1, j, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
};

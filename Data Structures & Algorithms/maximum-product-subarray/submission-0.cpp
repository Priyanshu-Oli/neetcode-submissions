class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int curr = nums[i];

            int a = curr;
            int b = maxi * curr;
            int c = mini * curr;

            int newMax = max(a, max(b, c));
            int newMin = min(a, min(b, c));

            maxi = newMax;
            mini = newMin;

            ans = max(ans, maxi);
        }

        return ans;
    }
};
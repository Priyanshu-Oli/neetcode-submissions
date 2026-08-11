class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;

        recur(nums, current, 0);

        return ans;
    }

    void recur(vector<int>& nums, vector<int>& current, int index) {

        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // TAKE
        current.push_back(nums[index]);
        recur(nums, current, index + 1);

        // BACKTRACK
        current.pop_back();

        // DON'T TAKE
        recur(nums, current, index + 1);
    }
};
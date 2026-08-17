class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>current;
        sort(nums.begin(),nums.end());
        
        solve(nums, current, ans, 0);
        return ans;
    }

    void solve(vector<int>& nums, vector<int>& current,
               vector<vector<int>>& ans, int index) {

            ans.push_back(current);

        for(int i=index ;i<nums.size();i++){
            if(i >index && nums[i]==nums[i-1]){
                continue;
                }
        current.push_back(nums[i]);
        solve(nums, current, ans, i+ 1);
        current.pop_back();
        
            

        }
    }
};
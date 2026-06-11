class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                for(int k  =j+1;k<nums.size();k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        st.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
       vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

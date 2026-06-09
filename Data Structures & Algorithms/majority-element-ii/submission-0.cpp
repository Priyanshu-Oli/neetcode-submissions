class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;

        int n = nums.size();
        vector<int>res;
        for(int i = 0 ; i <nums.size();i++){
            
            mpp[nums[i]]++;

        }
        for(auto m:mpp){
            if(m.second > (n/3)){
                res.push_back(m.first);
            }
        }
        return res;
    }
};
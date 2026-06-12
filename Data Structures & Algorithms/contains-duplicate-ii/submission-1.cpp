class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int previdx=0;
        
        // for(int i =0 i <nums.size();i++){
        //     mpp[nums[i]]++;
        // }
        for(int i =0;i< nums.size();i++){
            if(mpp.find(nums[i]) != mpp.end()){
                previdx = mpp[nums[i]];
            if(abs(i-previdx)<=k){
                return true;
            }
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j =0;
        int count =0;
        int ans=0;

        while(j < nums.size()){
            if(nums[j]==1){
                count++;
            }
            else{

            count=0;
            }
            ans = max(ans,count);
            j++;
        }
        return ans;
    }
};
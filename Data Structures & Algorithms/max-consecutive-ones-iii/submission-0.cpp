class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0,j = 0;
        int zeroes =0;
        int ans=0;

        while(j <nums.size()){
            if(nums[j]==0){
                zeroes++;
            }
            while(zeroes >k){
                if(nums[i]==0){
                    zeroes--;

                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
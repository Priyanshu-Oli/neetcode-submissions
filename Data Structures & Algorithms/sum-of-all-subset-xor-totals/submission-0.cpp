class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(0,0,nums);
    }

    int solve(int index, int curXor, vector<int>nums){
        if(index == nums.size()){
            return curXor;
        }
        int pick =solve(index+1, curXor^nums[index],nums);
        int notPick =solve(index+1, curXor,nums);

        return pick+notPick;

    }
};
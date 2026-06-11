class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    k %= nums.size();

    for(int i = 0; i < k; i++) {
        rotatebyone(nums);
    }
}

    vector<int> rotatebyone(vector<int>& nums) {
    int temp = nums[nums.size() - 1];

    for(int i = nums.size() - 1; i > 0; i--) {
        nums[i] = nums[i - 1];
    }

    nums[0] = temp;
    return nums;
}
};
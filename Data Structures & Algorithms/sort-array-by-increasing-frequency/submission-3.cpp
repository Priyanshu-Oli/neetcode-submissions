class Solution {
public:
    static unordered_map<int, int> count;

    static bool compare(int a, int b) {
        if (count[a] != count[b])
            return count[a] < count[b];

        return a > b;
    }

    vector<int> frequencySort(vector<int>& nums) {
        count.clear();
        for (int num : nums) {
            count[num]++;
        }

        sort(nums.begin(), nums.end(), compare);

        return nums;
    }
};

// Definition
unordered_map<int, int> Solution::count;
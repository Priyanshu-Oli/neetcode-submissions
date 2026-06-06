class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Put numbers into buckets according to frequency
        for (auto p : freq) {
            int num = p.first;
            int count = p.second;

            bucket[count].push_back(num);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = nums.size(); i >= 1; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
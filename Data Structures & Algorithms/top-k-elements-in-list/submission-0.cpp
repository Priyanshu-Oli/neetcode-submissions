class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        // Copy to vector
        vector<pair<int, int>> v(mpp.begin(), mpp.end());

        // Sort by frequency descending
        sort(v.begin(), v.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> ans;

        // Take top k frequent elements
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
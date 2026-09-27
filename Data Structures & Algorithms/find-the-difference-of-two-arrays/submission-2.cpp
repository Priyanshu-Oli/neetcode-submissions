class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1Set(nums1.begin(), nums1.end());
        unordered_set<int> num2Set(nums2.begin(), nums2.end());
        vector<int> res1, res2;

        for (int num : num1Set) {
            if (num2Set.find(num) == num2Set.end()) res1.push_back(num);
        }

        for (int num : num2Set) {
            if (num1Set.find(num) == num1Set.end()) res2.push_back(num);
        }

        return {res1, res2};
    }
};
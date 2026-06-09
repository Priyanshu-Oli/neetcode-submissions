class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;

        
        for (int num : nums) {
            s.insert(num);
        }

        int longest = 0;

        for (int num : nums) {

        
            if (s.find(num - 1) == s.end()) {

                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
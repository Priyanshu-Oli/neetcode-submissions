
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();

        int ans = 0;
        unordered_map<char, int> freq;

        while (j < n) {
            // Add the new character
            freq[s[j]]++;

            // Shrink while the window has a duplicate
            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            // Update the maximum length
            ans = max(ans, j - i + 1);

            // Expand the window
            j++;
        }

        return ans;
    }
};


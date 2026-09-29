class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int maxFreq = 0;
        int res = 0;

        int count[26] = {0};

        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;

            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
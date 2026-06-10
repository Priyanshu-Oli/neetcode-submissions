class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        if (s.size() == 1 || s.size() == 2) {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;

            } else {
               return isPalindrome(s,left+1,right)||isPalindrome(s,left,right-1);
                
            }
        }
        return true;
    }
    bool isPalindrome(string &s,int left, int right) {

        while (left < right) {

            if (s[left] == s[right]) {
                left++;
                right--;

            } else {
                return false;
            }
        }
        return true;
    }
};
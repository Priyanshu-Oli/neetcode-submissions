class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0 ;
        int right = s.size()-1;

        while(left<right){
            if(!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if(!isalnum(s[right]))
            {
                right--;
                continue;
            }
            s[left]=tolower(s[left]);
            s[right]=tolower(s[right]);

            if(s[left]==s[right]){
                left++;
                right--;

            }
            else{
                return false;
            }
        }
        return true;
        
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> phone = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        string current;

        solve(0, digits, current, ans, phone);

        return ans;
    }

    void solve(int index, string& digits, string& current,
               vector<string>& ans, vector<string>& phone) {

        // Base case
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters = phone[digits[index] - '0'];

        // Try every possible letter
        for (char ch : letters) {

            current.push_back(ch);

            // Move to the next digit
            solve(index + 1, digits, current, ans, phone);

            // Undo the choice
            current.pop_back();
        }
    }
};
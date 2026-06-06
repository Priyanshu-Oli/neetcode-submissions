class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";

        for (string s : strs) {
            ans += to_string(s.length());
            ans += '#';
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.length()) {

            string len = "";

            // Read length
            while (s[i] != '#') {
                len += s[i];
                i++;
            }

            int length = stoi(len);

            // Skip '#'
            i++;

            // Read the actual word
            string word = "";

            for (int j = 0; j < length; j++) {
                word += s[i];
                i++;
            }

            ans.push_back(word);
        }

        return ans;
    }
};
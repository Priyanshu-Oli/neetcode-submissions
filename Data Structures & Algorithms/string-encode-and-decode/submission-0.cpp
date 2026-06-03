class Solution {
public:
    string encode(vector<string>& strs) {
        vector<int> sizes;
        string res = "";

        // store sizes
        for (string s : strs) {
            sizes.push_back(s.size());
        }

        // add sizes with commas
        for (int sz : sizes) {
            res += to_string(sz) + ',';
        }

        // separator
        res += '#';

        // add actual strings
        for (string s : strs) {
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        int i = 0;

        // read sizes until '#'
        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }

        // skip '#'
        i++;

        // split strings according to sizes
        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};

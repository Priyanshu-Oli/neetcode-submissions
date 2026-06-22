class Solution {
public:
    string decodeString(string s) {

        // Stack stores:
        // {string before '[', repeat count}
        stack<pair<string, int>> st;

        string curr = "";   // Current decoded string at this level
        int num = 0;        // Current repeat count

        for (char ch : s) {

            // Case 1: Build the repeat count
            // Handles multi-digit numbers like 12[a]
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Case 2: Start of a new nested level
            else if (ch == '[') {

                // Save current context
                st.push({curr, num});

                // Reset for decoding the substring inside brackets
                curr = "";
                num = 0;
            }

            // Case 3: End of current nested level
            else if (ch == ']') {

                // Retrieve previous context
                string prev = st.top().first;
                int repeat = st.top().second;
                st.pop();

                // Repeat the current decoded substring
                string expanded = prev;

                for (int i = 0; i < repeat; i++) {
                    expanded += curr;
                }

                // Update current string with the expanded result
                curr = expanded;
            }

            // Case 4: Regular alphabet character
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
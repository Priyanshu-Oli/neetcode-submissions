class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; // {temperature, index}
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {

            while (!st.empty() && temperatures[i] > st.top().first) {
                auto top = st.top();
                st.pop();

                res[top.second] = i - top.second;
            }

            st.push({temperatures[i], i});
        }

        return res;
    }
};
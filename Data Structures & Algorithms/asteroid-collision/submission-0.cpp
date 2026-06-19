class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int current = 0;
        for (auto current : asteroids) {
            bool alive = true;
            while (!st.empty() && st.top() > 0 && current < 0 && alive) {
                if (abs(st.top()) < abs(current)) {
                    st.pop();
                } else if (abs(st.top()) == abs(current)) {
                    st.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }
            if (alive) {
                st.push(current);
            }
        }
        vector<int> result(st.size());

        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cars;

        // Store {position, speed}
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort cars by position (ascending)
        sort(cars.begin(), cars.end());

        stack<double> st;

        // Traverse from the car closest to target
        for (int i = cars.size() - 1; i >= 0; i--) {

            int pos = cars[i].first;
            int spd = cars[i].second;

            double time = (double)(target - pos) / spd;

            st.push(time);

            // Current car catches the fleet ahead
            if (st.size() >= 2 && st.top() <= [&]() {
                    double curr = st.top();
                    st.pop();
                    double prev = st.top();
                    st.push(curr);
                    return prev;
                }()) {

                st.pop();
            }
        }

        return st.size();
    }
};
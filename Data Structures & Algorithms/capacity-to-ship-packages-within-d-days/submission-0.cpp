class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int day = 1;
            int curr = 0;

            for (int w : weights) {
                if (curr + w > mid) {
                    day++;
                    curr = 0;
                }
                curr += w;
            }

            if (day <= days) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};
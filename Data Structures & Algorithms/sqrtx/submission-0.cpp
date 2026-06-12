class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int ans = 0;   // last valid answer

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long sq = (long long)mid * mid;

            if (sq <= x) {
                ans = mid;      // save valid candidate
                l = mid + 1;    // try to find a larger one
            }
            else {
                r = mid - 1;    // mid is too large
            }
        }

        return ans;
    }
};
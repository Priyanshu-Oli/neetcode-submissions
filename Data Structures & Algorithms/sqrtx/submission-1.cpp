class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if ((long long)mid * mid <= x) {
                res = mid;      
                l = mid + 1;    
            }
            else {
                r = mid - 1;
            }
        }

        return res;
    }
};
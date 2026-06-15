/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearch(MountainArray &mountainArr,
                     int target,
                     int left,
                     int right,
                     bool ascending) {

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);

            if (value == target) {
                return mid;
            }

            if (ascending) {
                if (value < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // Array is sorted in decreasing order
                if (value < target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        // Find the peak index
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int peak = left;

        // Search in the increasing part
        int ans = binarySearch(
            mountainArr,
            target,
            0,
            peak,
            true
        );

        if (ans != -1) {
            return ans;
        }

        // Search in the decreasing part
        return binarySearch(
            mountainArr,
            target,
            peak + 1,
            n - 1,
            false
        );
    }
};
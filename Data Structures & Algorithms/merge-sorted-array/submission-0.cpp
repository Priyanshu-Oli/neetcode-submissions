class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int midx = m-1;
        int nidx = n-1;

        int zidx =m+n-1;
        while(midx>=0&& nidx>=0){
            if(nums1[midx] > nums2[nidx]){
                nums1[zidx]=nums1[midx];
                midx--;
            }
            else{
                nums1[zidx]= nums2[nidx];
                nidx--;
            }
            zidx--;
        }
        while(nidx>=0){
            nums1[zidx] = nums2[nidx];
            nidx--;
            zidx--;
        }
        return;
    }
};
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);


        for(int i =0;i<n;i++){
            int rm = -1;
            for(int j = i+1;j< n ;++j){
                rm = max(rm,arr[j]);
            }
            ans[i] = rm;
        }
        return ans;
    }
};
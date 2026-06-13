class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l= 1;
        int r  = *max_element(piles.begin(), piles.end());
        int res = r;
     
        while(l<=r){
            long long hours=0;
            int k = (l+r)/2;
            for(int p:piles)
            hours+=(p +k-1)/k;
            if(hours<=h){
                res = min(k,res);
                r= k-1;
            }
            else{
                l= k+1;
            }
        }
        return res;
    }
};

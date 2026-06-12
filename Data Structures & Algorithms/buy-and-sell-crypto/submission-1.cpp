class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0 ;
         int r = 1;
         int profit = 0;
         int maxp=0;

         while(r < prices.size())
{
    if(prices[r] < prices[l])
    {
        l = r;
    }
    else
    {
        profit = prices[r] - prices[l];
        maxp = max(maxp, profit);
    }

    r++;

         }
         return maxp;
    }
};

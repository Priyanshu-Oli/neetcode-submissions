class Solution {
public:
    bool solve(int index, vector<int>& matchsticks, vector<int>& sides, int target) {
        
        if (index == matchsticks.size())
            return true;

        for (int i = 0; i < 4; i++) {
            
            if (sides[i] + matchsticks[index] <= target) {
                
                sides[i] += matchsticks[index];

                if (solve(index + 1, matchsticks, sides, target))
                    return true;

                sides[i] -= matchsticks[index]; // backtrack
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        
        int sum = 0;

        for (int x : matchsticks)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        vector<int> sides(4, 0);

        sort(matchsticks.rbegin(), matchsticks.rend());

        return solve(0, matchsticks, sides, target);
    }
};
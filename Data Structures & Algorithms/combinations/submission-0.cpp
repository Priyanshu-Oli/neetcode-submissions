class Solution {
public:
    vector<vector<int>> ans;
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        vector<int> comb;

        solve(1, comb);

        return ans;
    }

    void solve(int start, vector<int> comb) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++) {
            comb.push_back(i);
            solve(i + 1, comb);
            comb.pop_back();
        }
    }
};

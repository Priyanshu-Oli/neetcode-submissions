class Solution {
   public:
    vector<int> diffWaysToCompute(string expression) {
        vector<long long> numbers;
        vector<char> ops;
        long long value = 0;
        for (char c : expression) {
            if (c >= '0' && c <= '9')
                value = value * 10 + c - '0';
            else {
                numbers.push_back(value);
                value = 0;
                ops.push_back(c);
            }
        }
        numbers.push_back(value);
        int n = numbers.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n));
        for (int i = 0; i < n; i++) dp[i][i] = {numbers[i]};
        for (int len = 2; len <= n; len++)
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;
                for (int mid = l; mid < r; mid++)
                    for (long long a : dp[l][mid])
                        for (long long b : dp[mid + 1][r]) {
                            char op = ops[mid];
                            dp[l][r].push_back(op == '+' ? a + b : op == '-' ? a - b : a * b);
                        }
            }
        return vector<int>(dp[0][n - 1].begin(), dp[0][n - 1].end());
    }
};

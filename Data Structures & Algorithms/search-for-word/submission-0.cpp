class Solution {
public:

    bool solve(vector<vector<char>>& board, string& word,
               int i, int j, int k) {

        // We found the complete word
        if (k == word.size()) {
            return true;
        }

        // Invalid position or wrong character
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[k]) {
            return false;
        }

        // Save the character
        char temp = board[i][j];

        // Mark cell as visited
        board[i][j] = '#';

        // Try all 4 directions
        bool found =
            solve(board, word, i + 1, j, k + 1) ||  // down
            solve(board, word, i - 1, j, k + 1) ||  // up
            solve(board, word, i, j + 1, k + 1) ||  // right
            solve(board, word, i, j - 1, k + 1);    // left

        // Undo the change (backtracking)
        board[i][j] = temp;

        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Try every cell as the starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
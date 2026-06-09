class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> boxes;

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                char num = board[r][c];

                if (num == '.') {
                    continue;
                }

                string boxKey =
                    to_string(r / 3) + "," + to_string(c / 3);

                if (rows[r].count(num) ||
                    cols[c].count(num) ||
                    boxes[boxKey].count(num)) {

                    return false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                boxes[boxKey].insert(num);
            }
        }

        return true;
    }
};
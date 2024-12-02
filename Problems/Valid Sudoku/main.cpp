class Solution {
public:
    bool check(int i, int j, vector<vector<char>>& board) {
        bool square[9] = {false};
        for (int r = i; r < i + 3; r++) {
            for (int c = j; c < j + 3; c++) {
                if (board[r][c] == '.')
                    continue;
                int number = board[r][c] - '1';
                if (number < 0 || number > 8 || square[number])
                    return false;
                square[number] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int number = board[i][j] - '1';
                if (number < 0 || number > 8 || 
                    rows[i][number] || cols[j][number])
                    return false;
                rows[i][number] = true;
                cols[j][number] = true;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3)
                if (!check(i, j, board))
                    return false;
        }
        return true;
    }
};

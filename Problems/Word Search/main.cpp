class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int row, int col, vector<vector<char>>& board, string word, int index) {
        if (index == word.length())
            return true;

        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() &&
            board[row][col] != '#' && board[row][col] == word[index]) {
                char character = board[row][col];
                board[row][col] = '#';
                for (auto pos : dir)
                    if (dfs(row + pos.first, col + pos.second, board, word, index + 1))
                        return true;
                board[row][col] = character;
            }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0]) {
                   if (dfs(row, col, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

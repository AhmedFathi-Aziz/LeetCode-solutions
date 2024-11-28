class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int index) {
        if (word.size() == index)
            return true;
        if (i < 0 || j < 0 || i == board.size() ||
            j == board[0].size() || board[i][j] != word[index])
            return false;
        char character = board[i][j];
        board[i][j] = '#';
        bool out = ( 
            dfs(i + 1, j, board, word, index + 1) ||
            dfs(i - 1, j, board, word, index + 1) ||
            dfs(i, j + 1, board, word, index + 1) ||
            dfs(i, j - 1, board, word, index + 1)
        );
        board[i][j] = character;
        return out;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0])
                    if (dfs(i, j, board, word, 0))
                        return true;
        return false;
    }
};

class Solution {
private:
    int rows = 0;
    int cols = 0;
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int index) {
        if (index == word.size())
            return true;
        
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[index])
            return false;

        char ch = board[i][j];
        board[i][j] = '#';
        bool ret = (
            dfs(i + 1, j, board, word, index + 1) ||
            dfs(i - 1, j, board, word, index + 1) ||
            dfs(i, j + 1, board, word, index + 1) ||
            dfs(i, j - 1, board, word, index + 1)
        );
        board[i][j] = ch;
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == word[0])
                    if (dfs(i, j, board, word, 0))
                        return true;
        return false;
    }
};

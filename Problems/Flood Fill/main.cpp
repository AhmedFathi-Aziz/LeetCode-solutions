class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int color, int col) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != col)
            return;
        image[i][j] = color;
        fill(image, i - 1, j, color, col);
        fill(image, i + 1, j, color, col);
        fill(image, i, j + 1, color, col);
        fill(image, i, j - 1, color, col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
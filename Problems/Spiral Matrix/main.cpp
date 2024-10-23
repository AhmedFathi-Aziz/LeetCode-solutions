class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int i = 0;
        vector<int> spiral;
        while (top <= bottom and left <= right) {
            i = left;
            while (i <= right)
                spiral.push_back(matrix[top][i++]);   
            ++top;
            i = top;
            while (i <= bottom)
                spiral.push_back(matrix[i++][right]);
            --right;
            if (left > right || top > bottom)
                return spiral;
            i = right;
            while (i >= left)
                spiral.push_back(matrix[bottom][i--]);
            --bottom;
            i = bottom;
            while (i >= top)
                spiral.push_back(matrix[i--][left]);
            ++left;
        }
        return spiral;
    }
};

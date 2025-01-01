bool check(vector<vector<int>> &maze, int i, int j) {
	if (i < 0 || j < 0 || i == maze.size() || 
		j == maze[i].size() || maze[i][j] == 0) {
		return false;
	}
	if (i == maze.size() - 1 and j == maze[i].size() - 1)
		return true;
	if (check(maze, i, j + 1))
		return true;
	if (check(maze, i + 1, j))
		return true;
	return false;
}

bool canGetCheese(vector<vector<int> > &maze) {
	return check(maze, 0, 0);
}

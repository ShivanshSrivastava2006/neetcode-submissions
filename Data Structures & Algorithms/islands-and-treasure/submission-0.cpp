class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        // Multi-source initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = true;
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = node.first + dx[k];
                int ny = node.second + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (!visited[nx][ny] && grid[nx][ny] != -1) {
                        visited[nx][ny] = true;
                        distance[nx][ny] = distance[node.first][node.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Copy back to grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1)
                    grid[i][j] = -1;
                else
                    grid[i][j] = distance[i][j];
            }
        }
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        // push all rotten oranges (multi-source)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        int time = 0;

        while(!q.empty()) {
            int sz = q.size();   // size of current level
            bool rotted = false;

            for(int k = 0; k < sz; k++) {
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }

            if (rotted) time++;  // only increment if something changed
        }

        // check if any fresh orange remains
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<int, int>>q;
        
        vector<int>dx = {1, 0, -1, 0};
        vector<int>dy = {0, 1, 0, -1};

        int count = 0;

        int maxarea = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    pair<int, int> start = {i, j};
                    visited[i][j] = true;
                    q.push({i, j});
                    count++;
                    int area = 0;
                    while(!q.empty())
                    {
                        pair<int, int>p = q.front();
                        q.pop();
                        area++;
                        for(int k = 0; k < 4; k++)
                        {
                            int nx = p.first + dx[k];
                            int ny = p.second + dy[k];

                            if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                            {
                                if(grid[nx][ny] == 1 && !visited[nx][ny])
                                {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }
};

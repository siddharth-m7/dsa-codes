class Solution {
   public:
    bool bfsAt(int i, int j, int m, int n, vector<vector<int>>& h, vector<vector<bool>>& vis) {
        if (i == m - 1 || j == n - 1) return true;

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int newy = i + y[k];
            int newx = j + x[k];
            
            if (newy < m && newy >= 0 && newx < n && newx >= 0 && !vis[newy][newx] && h[newy][newx] <= h[i][j]) {
                vis[newy][newx] = true;
                if (bfsAt(newy, newx, m, n, h, vis)) return true;
            }
        }
        return false;
    }

    bool bfsPaci(int i, int j, int m, int n, vector<vector<int>>& h, vector<vector<bool>>& visi) {
        if (i == 0 || j == 0) return true;
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++) {
            int newy = i + y[k];
            int newx = j + x[k];
            
            if (newy < m && newy >= 0 && newx < n && newx >= 0 && !visi[newy][newx] && h[newy][newx] <= h[i][j]) {
                visi[newy][newx] = true;
                if (bfsPaci(newy, newx, m, n, h, visi)) return true;
            }
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visi(m, vector<bool>(n, false));
                visi[i][j] = true;
                if (bfsPaci(i, j, m, n, h, visi)) {
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    vis[i][j] = true;
                    if (bfsAt(i, j, m, n, h, vis)) {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};
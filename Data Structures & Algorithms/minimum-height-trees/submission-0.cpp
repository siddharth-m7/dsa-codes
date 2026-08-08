class Solution {
   public:
    int height(vector<vector<int>>& adj, int n, int i) {
        vector<int> visi(n, 0);

        queue<int> q;
        q.push(i);
        int h = 0;
        while (!q.empty()) {
            h++;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node]) {
                    if (visi[it] == 0) {
                        q.push(it);
                        visi[node] = 1;
                    }
                }
            }
        }
        return h;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int minHeight = INT_MAX;

        vector<int> heights(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            heights[i] = height(adj, n, i);
            minHeight = min(minHeight, heights[i]);
        }
        // cout<<minHeight;
        for (int i = 0; i < n; i++) {
            if(heights[i] == minHeight)
                ans.push_back(i);
        }

        return ans;
    }
};
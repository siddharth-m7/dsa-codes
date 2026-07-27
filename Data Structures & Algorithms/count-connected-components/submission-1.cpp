class Solution {
public:
    void dfs(vector<vector<int>>& adj, int curr, vector<int>& visi){
        visi[curr] = 1;

        for(auto i : adj[curr]) {
            if(visi[i] == 0) {
                dfs(adj, i, visi);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visi(n,0);
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(visi[i]) continue;
            ans++;
            dfs(adj, i, visi);
        }

        return ans;
    }
};

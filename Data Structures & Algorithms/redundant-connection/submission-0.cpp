class Solution {
   public:
    bool findCycleDFS(int node, int parent_node, const vector<vector<int>>& adj,
                      vector<bool>& visited, vector<int>& parent, vector<int>& cycle) {
        visited[node] = true;
        parent[node] = parent_node;

        for (int neighbor : adj[node]) {
            if (neighbor == parent_node) {
                continue;
            }
            if (visited[neighbor]) {
                int curr = node;
                cycle.push_back(neighbor);
                while (curr != neighbor) {
                    cycle.push_back(curr);
                    curr = parent[curr];
                }
                cycle.push_back(neighbor);
                return true;
            }
            if (!visited[neighbor]) {
                if (findCycleDFS(neighbor, node, adj, visited, parent, cycle)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        vector<bool> visited(n + 1, false);
        vector<int> parent(n + 1, -1);
        vector<int> cycle;

        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        findCycleDFS(1, -1, adj, visited, parent, cycle);
        vector<int> ans;
        int gr=0;
        for (int j = cycle.size() - 1; j > 0; j--) {
            // cout << cycle[j] << (j == 0 ? "" : " -> ");
            int e1 = cycle[j];
            int e2 = cycle[j-1];
            for(int i = 0; i<n; i++) {
                if((edges[i][0] == e1 && edges[i][1] == e2) || (edges[i][0] == e2 && edges[i][1] == e1)) {
                    gr = max(gr,i);
                }
            }
        }

        return edges[gr];
    }
};

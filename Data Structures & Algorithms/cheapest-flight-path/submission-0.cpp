class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector < vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int sr = flights[i][0];
            int ds = flights[i][1];
            int wt = flights[i][2];
            adj[sr].push_back({ds, wt});
        }

        int ans = INT_MAX;
        queue<pair<int, pair<int,int>>> q;
        q.push({src, {0, 0}});
        vector<int> dist(n, INT_MAX);
        while (!q.empty()) {
            int sr = q.front().first;
            int curr_price = q.front().second.first;
            int curr_k = q.front().second.second;
            cout<<sr<<" "<<curr_price<<" "<<curr_k<<endl;
            q.pop();
            
            if (sr == dst) {
                ans = min(ans, curr_price);
            }
            if (curr_k > k) continue;

            for (int i = 0; i < adj[sr].size(); i++) {
                int cur = adj[sr][i].first;
                if (dist[cur] > curr_price + adj[sr][i].second) {
                    dist[cur] = curr_price + adj[sr][i].second;
                    q.push({cur, {curr_price + adj[sr][i].second, curr_k + 1}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

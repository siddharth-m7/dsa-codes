class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visi(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto ne : adj[node]) {
                if(visi[ne] == 0 || ne == par) {
                    if( ne != par ) {
                        visi[ne] = 1;
                        q.push({ne,node});
                    }
                }
                else {
                    return false;
                }
            }
        }
        if(cnt != n) return false;
        return true;
    }
};

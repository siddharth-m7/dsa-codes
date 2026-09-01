class Solution {
public:
    bool isFound(vector<vector<int>>& graph, int dep, int target, vector<int>& visi) {
        if(dep == target) return true;
        if(visi[dep]) return false;
        visi[dep] = true;
        bool ans = false;
        for(int i = 0; i < graph[dep].size(); i++ ) {
            ans = ans | isFound(graph, graph[dep][i], target, visi);
        }

        return ans;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);

        for(auto p : prerequisites) {
            int dep = p[1];
            int det = p[0];

            graph[dep].push_back(det);
        }

        vector<bool> ans(queries.size());
        for(int i = 0; i<queries.size(); i++) {
            vector<int> visi(numCourses, 0);
            int dep = queries[i][1];
            int target = queries[i][0];

            ans[i] = isFound(graph, dep, target, visi);
        }

        return ans;
    }
};
class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> freq(26, 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                freq[words[i][j] - 'a'] = 1;
            }
            for (int j = i + 1; j < words.size(); j++) {
                string w1 = words[i];
                string w2 = words[j];
                int k = 0;
                int minLen = min(w1.size(), w2.size());
                if (w1.size() > w2.size() && w1.substr(0, minLen) == w2) {
                    return "";
                }
                while (w1[k] == w2[k]) {
                    k++;
                    if (k >= w1.size() || k >= w2.size()) break;
                }
                if (k < w1.size() && k < w2.size()) {
                    int one = w1[k] - 'a';
                    int two = w2[k] - 'a';
                    adj[one].push_back(two);
                }
            }
        }

        int n = 0;
        for (int f : freq) {
            if (f == 1) n++;
        }

        vector<int> indegree(26, 0);

        for (auto it : adj) {
            for (auto i : it) {
                indegree[i]++;
            }
        }
        string topo = "";
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && freq[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            char c = 'a' + node;
            topo.push_back(c);

            for (int neig : adj[node]) {
                indegree[neig]--;
                if (indegree[neig] == 0) {
                    q.push(neig);
                }
            }
        }
        cout << topo << endl;
        if (topo.size() == n) return topo;
        return "";
    }
};

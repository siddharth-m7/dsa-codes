class Solution {
public:
    bool isMatch(vector<int>& freq, vector<int>& freq2) {
        for(int i = 0; i < 70; i++) {
            if(freq2[i] < freq[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> freq(70,0);
        for(char c : t) {
            freq[c - 'A']++;
        }
        int ans = s.size() + 1;
        int ansl = -1;
        int ansr = -1;
        int l = 0, r = 0;
        int n = s.size();
        vector<int> freq2 (70,0);
        while(l<n && r<n){
            freq2[s[r] - 'A']++;

            while(isMatch(freq, freq2)) {
                if(r - l + 1 < ans) {
                    ans = r - l + 1;
                    ansl = l;
                    ansr = r;
                }
                freq2[s[l] - 'A']--;
                l++;
            }
            r++;
        }

        if(ansl == -1) return "";
        // return "";
        return s.substr(ansl, ans);
    }
};

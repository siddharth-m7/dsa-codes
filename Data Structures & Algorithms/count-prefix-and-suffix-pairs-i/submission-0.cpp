class Solution {
public:
    bool isPrefixandSuffix(string&a, string&b){
        int n = a.size();
        int nn = b.size();
        if(n > nn) return false;
        if(b.substr(0,n) == a && b.substr(nn-n, n) == a) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                if(isPrefixandSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};
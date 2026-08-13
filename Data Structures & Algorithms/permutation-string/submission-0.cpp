class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> one(26,0);
        vector<int> two(26,0);
        int n1 = s1.size();
        int n2 = s2.size();

        if(n2 < n1) return false;

        for(char c : s1) {
            one[c-'a']++;
        }
        int i =0;
        for(;i<n1;i++){
            two[s2[i]-'a']++;
        }

        if(two == one) return true;
        int j = 0;
        for(; i<n2; i++) {
            two[s2[j] - 'a']--;
            two[s2[i] - 'a']++;
            j++;
            if(one == two) return true;
        }

        return false;

    }
};

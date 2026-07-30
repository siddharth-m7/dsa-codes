class Solution {
public:
    bool isPal(string& s) {
        string cpy = s;
        reverse(cpy.begin(), cpy.end());
        if(cpy == s) return true;
        return false;
    }
    bool validPalindrome(string s) {
        if(isPal(s)) return true;

        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            s.erase(s.begin() + i);
            // cout<<s<<endl;
            if(isPal(s)) return true;
            s.insert(i,1,c);
            // cout<<s<<endl;
        } 
        return false;
    }
};
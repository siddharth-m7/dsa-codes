class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0;
        int cntStar = 0;
        for(char c : s) {
            if(c == '(') cnt++;
            else if (c == ')') cnt--;
            else cntStar++;

            if(cnt + cntStar < 0) return false;
        }
        
        cnt = 0;
        cntStar = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == ')') cnt++;
            else if (s[i] == '(') cnt--;
            else cntStar++;

            if(cnt + cntStar < 0) return false;
        }
        
        return true;
    }
};
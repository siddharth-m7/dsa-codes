class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0;
        int bill10 = 0;
        for(int bill : bills) {
            if(bill == 5) {
                bill5++;
            }
            else if(bill == 10){
                if(bill5 == 0) return false;
                bill5--;
                bill10++;
            }
            else {
                if(bill10 > 0 && bill5 > 0) {
                    bill10--;
                    bill5--;
                }
                else if(bill5 > 2) {
                    bill5 -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};
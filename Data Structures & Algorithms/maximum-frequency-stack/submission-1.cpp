class FreqStack {
    vector<int> temp;
    unordered_map<int,int> freq;
public:
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;
        temp.push_back(val);  
    }
    
    int pop() {
        int maxfreq = 0;
        int maxelem = -1;
        for(auto it:temp){
            if(it == -1) continue;
            int curr = freq[it];
            if(curr >= maxfreq) {
                maxfreq = curr;
                maxelem = it;
            }
        }
        for(int i = temp.size()-1; i>=0; i--){
            if(temp[i] == maxelem){
                temp[i] = -1;
                break;
            }
        }
        freq[maxelem]--;
        return maxelem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
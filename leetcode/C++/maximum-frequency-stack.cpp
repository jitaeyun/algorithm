

class FreqStack {
public:
    int idx;
    unordered_map<int,stack<int>> um;
    priority_queue<vector<int>,vector<vector<int>>> pq;
    FreqStack() {
        idx=0;
    }
    
    void push(int val) {
        um[val].push(++idx);
        pq.push({(int)um[val].size(), idx, val});
    }
    
    int pop() {
        if(pq.empty()) return -1;
        int val = pq.top()[2]; pq.pop();
        um[val].pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
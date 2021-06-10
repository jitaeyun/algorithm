class MyCalendarTwo {
public:
    vector<vector<int>> v;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        int idx = v.size();
        int mn=start,mx=end;
        vector<vector<int>> t;
        for(int i=0; i<v.size(); ++i){
            mn=max(v[i][0],start);
            mx=min(v[i][1],end);
            if(mx>mn) {
                for(int j=0; j<t.size(); ++j){
                    if(max(mn,t[j][0])<min(mx,t[j][1])) return false;
                }
                t.push_back({mn,mx});
            }
            if(idx==v.size() && start<v[i][0]) idx=i;
        }
        v.insert(v.begin() + idx, {start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
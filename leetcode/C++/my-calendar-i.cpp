class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {}
    
    bool book(int start, int end) {
        int idx=v.size();
        for(int i=0; i<v.size(); ++i){
            if(max(start,v[i][0])<min(end,v[i][1])) return false;
            if(start<v[i][0]) {idx=i; break;}
        }
        v.insert(v.begin()+idx,{start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class Solution {
public:
    static bool compare(string &a, string &b){
        string sa=a.substr(a.find(" ")+1), sb=b.substr(b.find(" ")+1);
        if(sa==sb) return a<b;
        return sa<sb;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ll,dl;
        char c;
        for(string &s : logs){
            c=s.substr(s.find(" ")+1)[0];
            if('0'<=c && c<='9') dl.push_back(s);
            else ll.push_back(s);
        }
        sort(ll.begin(),ll.end(),compare);
        for(string &s : dl) ll.push_back(s);
        return ll;
    }
};
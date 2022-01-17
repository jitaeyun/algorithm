class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, string> um, rum;
        unordered_map<string, string>::iterator it;
        stringstream ss(s);
        string temp, t;
        int idx = 0;
        while (getline(ss, temp, ' ')) {
            if(idx >= pattern.length()) return false;
            t = to_string(pattern[idx]);
            it = um.find(t);
            if(it == um.end()) um[t] = temp;
            else if(it->second != temp) return false;
            
            it = rum.find(temp);
            if(it == rum.end()) rum[temp] = t;
            else if(it->second != t) return false;
            
            ++idx;
        }
        return idx == pattern.length();
    }
};
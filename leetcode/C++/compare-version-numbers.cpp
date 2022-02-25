class Solution {
public:
    void parsingVersion(string &version, vector<int> &v){
        string s;
        for(char &ch : version){
            if(ch=='.'){
                if(s.length()>0) v.push_back(stoi(s));
                s.clear();
            }
            else s.push_back(ch);
        }
        if(s.length()>0) v.push_back(stoi(s));
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int idx_1=0, idx_2=0;
        parsingVersion(version1, v1); parsingVersion(version2, v2);
        for(; idx_1<v1.size()&& idx_2<v2.size(); ++idx_1, ++idx_2){
            if(v1[idx_1]>v2[idx_2]) return 1;
            else if(v1[idx_1]<v2[idx_2]) return -1;
        }
        for(; idx_1<v1.size(); ++idx_1) if(v1[idx_1]>0) return 1;
        for(; idx_2<v2.size(); ++idx_2) if(v2[idx_2]>0) return -1;
        return 0;
    }
};
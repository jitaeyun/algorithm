class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s,sol;
        int m=0,t;
        unordered_map<string,int> um;
        unordered_set<string> ban;
        for(string &ss : banned) ban.insert(ss);
        for(int i=0; i<paragraph.length(); ++i){
            if(paragraph[i]>='a'&&paragraph[i]<='z') s.push_back(paragraph[i]);
            else if(paragraph[i]>='A'&&paragraph[i]<='Z') s.push_back(paragraph[i]-'A'+'a');
            else if(paragraph[i]==' ' || paragraph[i]==','){
                if(s.length()==0) continue;
                if(ban.find(s)==ban.end()){
                    t=++um[s];
                    if(m<t) {
                        m=t;
                        sol=s;
                    }
                }
                s.clear();
            }
        }
        if(ban.find(s)==ban.end()){
            t=++um[s];
            if(m<t){
                m=t;
                sol=s;
            }
        }
        return sol;
    }
};
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> us;
        for(int i=0,j=0,idx=0; i<emails.size(); ++i){
            string ln;
            idx=emails[i].find("@");
            for(j=0; j<idx; ++j){
                if(emails[i][j]=='.') continue;
                else if(emails[i][j]=='+') break;
                ln.push_back(emails[i][j]);
            }
            us.insert(ln+emails[i].substr(idx));
        }
        return us.size();
    }
};
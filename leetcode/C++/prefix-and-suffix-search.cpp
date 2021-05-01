class WordFilter {
public:
    unordered_map<string,int> m;
    WordFilter(vector<string>& words) {
        string prefix,suffix;
        for(int i=0; i<words.size(); ++i){
            prefix=""; 
            for(int j=0; j<words[i].length(); ++j){
                prefix+=words[i][j]; suffix="";
                for(int k=words[i].length()-1; k>=0; --k){
                    suffix=words[i][k]+suffix;
                    m[prefix+'-'+suffix]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s=prefix+'-'+suffix;
        unordered_map<string,int>::iterator it=m.find(s);
        if(it==m.end()) return -1;
        return it->second;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
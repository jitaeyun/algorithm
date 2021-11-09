class Solution {
public:
    unordered_map<int,int> um;
    void makeMap(string &word){
        int key=0;
        for(char &ch: word) key|=(1<<(ch-'a'));
        ++um[key];
    }
    int traverse(vector<int> &v, int num, int n){
        if(n==v.size()) {
            if(um.find(num)==um.end()) return 0;
            return um[num];
        }
        return traverse(v, num|v[n], n+1) + traverse(v, num, n+1);
    }
    int validWord(string &puzzle){
        int key=(1<<(puzzle[0]-'a')),basic=key,t=0;
        vector<int> v;
        for(int i=1; i<puzzle.length(); ++i){
            t=1<<(puzzle[i]-'a');
            if(key==(key|t)) continue;
            key|=t;
            v.push_back(t);
        }
        return traverse(v, basic, 0);
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> sol;
        for(string &word : words) makeMap(word);
        for(string &puzzle: puzzles) sol.push_back(validWord(puzzle));
        return sol;
    }
};
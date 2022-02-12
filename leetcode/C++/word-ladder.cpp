class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<int> visit(wordList.size()+1,0);
        unordered_map<string, vector<int>> um;
        queue<int> q;
        int ed=-1, idx=0;
        char ch='.';
        wordList.push_back(beginWord);
        for(int i=0; i<wordList.size(); ++i){
            if(ed == -1 && endWord == wordList[i]) ed=i;
            for(int j=0; j<wordList[i].length(); ++j){
                ch = wordList[i][j]; wordList[i][j]='.';
                um[wordList[i]].push_back(i);
                wordList[i][j] = ch;
            }
        }
        visit.back()=1; q.push((int)visit.size()-1);
        if(ed < 0) return 0;
        while(!q.empty()){
            idx = q.front(); q.pop();
            if(idx == ed) return visit[idx];
            for(int i=0; i<wordList[idx].length(); ++i){
                ch = wordList[idx][i]; wordList[idx][i]='.';
                vector<int> &v = um[wordList[idx]];
                for(int &n : v) if(idx!=n && visit[n]==0) {visit[n]=visit[idx]+1; q.push(n);}
                wordList[idx][i]=ch;
            }
        }
        return 0;
    }
};
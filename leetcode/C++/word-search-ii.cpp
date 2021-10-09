class NODE {
public:
    vector<NODE*> v;
    NODE(): v(26,nullptr) {}
};

class Solution {
public:
    int mx,my,dy[4]={0,0,1,-1},dx[4]={1,-1,0,0};
    NODE *node;
    void traverse(int &y,int &x, int idx,vector<vector<char>>& board, NODE *cur){
        int ny=0,nx=0;
        if(idx==10) return;
        if(cur->v[board[y][x]-'a']==nullptr) cur->v[board[y][x]-'a']=new NODE();
        cur = cur->v[board[y][x]-'a'];
        board[y][x]=-board[y][x];
        for(int i=0; i<4; ++i){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0 || ny>=my || nx<0 || nx>=mx || board[ny][nx]<0) continue;
            traverse(ny,nx,idx+1,board,cur);
        }
        board[y][x]=-board[y][x];
    }
    bool search_prefix(string &word){
        NODE *cur = node;
        for(char &ch : word){
            if(cur->v[ch-'a']==nullptr) return false;
            else cur=cur->v[ch-'a'];
        }
        return true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. init
        vector<string> sol;
        unordered_set<char> us;
        my=board.size(); mx=board[0].size();
        node = new NODE();
        for (string &word: words) us.insert(word[0]);
        // 2. traverse
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(us.find(board[i][j]) != us.end()) traverse(i,j,0,board,node);
            }
        }
        // 3. search prefix
        for(string &word : words){
            if(search_prefix(word)) sol.push_back(word);
        }
        return sol;
    }
};
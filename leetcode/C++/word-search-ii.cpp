class NODE {
public:
    vector<NODE*> v;
    int fin;
    NODE(): v(26,nullptr) {fin=0;}
};

class Solution {
public:
    vector<string> sol;
    int mx,my,dy[4]={0,0,1,-1},dx[4]={1,-1,0,0};
    NODE *node;
    void make_path(string &word, int &idx){
        NODE *cur = node;
        for(char &ch : word){
            if(cur->v[ch-'a']==nullptr) cur->v[ch-'a']=new NODE();
            cur=cur->v[ch-'a'];
        }
        cur->fin = idx+1;
    }
    void traverse(int &y,int &x, int idx, vector<vector<char>>& board, vector<string> &words, NODE *cur){
        int ny=0,nx=0;
        if(idx==10 || (cur=cur->v[board[y][x]-'a'])==nullptr) return;
        else if(cur->fin){
            sol.push_back(words[cur->fin-1]);
            cur->fin = 0;
        }
        board[y][x]=-board[y][x];
        for(int i=0; i<4; ++i){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0 || ny>=my || nx<0 || nx>=mx || board[ny][nx]<0) continue;
            traverse(ny,nx,idx+1,board,words,cur);
        }
        board[y][x]=-board[y][x];
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. init
        my=board.size(); mx=board[0].size(); node = new NODE();
        // 2. make path
        for (int i=0; i<words.size(); ++i) make_path(words[i], i);
        // 3. traverse
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                traverse(i,j,0,board,words,node);
            }
        }
        return sol;
    }
};
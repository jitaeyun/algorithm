class Solution {
public:
    vector<vector<int>> sol;
    void rotate(int &y, int &x, int &num, int &c){
        int cy=y, cx=x;
        if(c==1){
            sol[y][x]=num++;
            return;
        }
        for(int i=0; i<c-1; ++i){
            sol[cy][cx]=num++;
            cx+=1;
        }
        for(int i=0; i<c-1; ++i){
            sol[cy][cx]=num++;
            cy+=1;
            
        }
        for(int i=0; i<c-1; ++i){
            sol[cy][cx]=num++;
            cx-=1;
        }
        for(int i=0; i<c-1; ++i){
            sol[cy][cx]=num++;
            cy-=1;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        sol=vector<vector<int>>(n, vector<int>(n,0));
        for(int y=0,x=0,num=1,c=n; c>0; c-=2,++y,++x){
            rotate(y,x,num,c);
        }
        return sol;
    }
};
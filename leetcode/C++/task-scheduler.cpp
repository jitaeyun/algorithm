class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx=0,t=0;
        vector<int> v(26,0);
        for(char &ch : tasks) {++v[ch-'A']; mx=max(mx,v[ch-'A']);}
        for(int i=0; i<26; ++i) if(v[i]==mx) ++t;
        return max((int)tasks.size(),t+(mx-1)*(n+1));
    }
};
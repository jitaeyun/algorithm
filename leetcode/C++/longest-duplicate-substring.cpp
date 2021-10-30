class Solution {
public:
    string longestDupSubstring(string s) {
        string sol,t;
        int l=1,r=(int)s.length()-1,m=0;
        while(l<=r){
            m=(l+r)/2;
            t=rabinKarp(s,m);
            if(t.length()==0) r=m-1;
            else {
                sol=t;
                l=m+1;
            }
        }
        return sol;
    }
    const int mod = 10000007;
    string rabinKarp(string &s, int sz){
        string t;
        int hash=0,p=1;
        unordered_map<int,vector<int>> um;
        if(sz==0) return "";
        for(int i=0; i<sz; ++i) {
            hash=(hash*26+(s[i]-'a'))%mod;
            if(i>0) p=(p*26)%mod;
        }
        um[hash].push_back(0);
        for(int i=sz; i<s.length(); ++i){
            hash=(hash-(s[i-sz]-'a')*p+26*mod)%mod;
            hash=(hash*26+(s[i]-'a'))%mod;
            if(um.find(hash)==um.end()) um[hash].push_back(i-sz+1);
            else {
                t=s.substr(i-sz+1,sz);
                for(int &idx : um[hash]) if(t==s.substr(idx,sz)) return t;
                um[hash].push_back(i-sz+1);
            }
        }
        return "";
    }
};


/*
1) 처음써본 라빈카프 알고리즘 (기법자체는 어렵지 않았으나 해시를 잘 이해해야함)
2) 이진탐색의 접근법을 잘 떠올려야함
3) 종합: 어려웠고, 다시 풀만할 가치가 있는 문제
*/
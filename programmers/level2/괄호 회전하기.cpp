#include <string>
#include <vector>

using namespace std;

bool check(string &s){
    vector<char> v;
    for(int i=0; i<s.length(); ++i){
        if(s[i]=='['||s[i]=='('||s[i]=='{') v.push_back(s[i]);
        else {
            if(v.empty()) return false;
            else if(s[i]==']'&&v.back()=='[') v.pop_back();
            else if(s[i]==')'&&v.back()=='(') v.pop_back();
            else if(s[i]=='}'&&v.back()=='{') v.pop_back();
            else break;
        }
    }
    return v.empty();
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.length(); ++i){
        s=s.substr(1)+s[0];
        if(check(s)) ++answer;
    }
    return answer;
}
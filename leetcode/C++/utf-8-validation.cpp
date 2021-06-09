class Solution {
public:
    vector<string> v;
    void trans(int &d){
        string s;
        for(int i=128; i>0; i>>=1){
            if((d&i)) s.push_back('1');
            else s.push_back('0');
        }
        v.push_back(s);
    }
    bool validUtf8(vector<int>& data) {
        int sz = data.size(), state=0, bit=0;
        for(int &t : data) trans(t);
        for(int i=0; i<sz; ++i){
            for(int j=0; j<8; ++j){
                if(state==0){
                    if(v[i][0]=='0') break;
                    else if(v[i][j]=='1') ++bit;
                    else {
                        if(bit<=1 || bit>4) return false;
                        ++state; --bit;
                        break;
                    }
                }
                else {
                    if(v[i][0]=='1' && v[i][1]=='0') --bit;
                    else return false;
                    if(bit==0) state=0;
                    break;
                }
            }
        }
        return bit==0;
    }
};
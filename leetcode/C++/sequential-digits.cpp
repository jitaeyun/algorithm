class Solution {
public:
    int makeInitNum(int len){
        string num;
        for(int i=0; i<len; ++i) num.push_back(i+1+'0');
        return stoi(num);
    }
    int makeSumNum(int len){
        string num;
        for(int i=0; i<len; ++i) num.push_back('1');
        return stoi(num);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sol;
        int mn = to_string(low).length();
        int mx = to_string(high).length();
        for(int i=mn,n=0,p=0; i<=mx && i<10; ++i){
            n=makeInitNum(i); p=makeSumNum(i);
            for(int j=i; j<10; ++j,n+=p) {
                if(n>=low && n<=high) sol.push_back(n);
            }
        }
        return sol;
    }
};
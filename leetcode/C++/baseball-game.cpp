class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sol = 0;
        vector<int> v;
        for(string &op : ops){
            if(op=="+")  v.push_back(v.back()+v[(int)v.size()-2]);
            else if(op=="C") v.pop_back();
            else if(op=="D") v.push_back(v.back()*2);
            else v.push_back(stoi(op));
        }
        for(int &n : v) sol+=n;
        return sol;
    }
};
class Solution {
public:
    vector<string> v;
    void parsing(string &preorder){
        istringstream ss(preorder);
        string buf;
        while (getline(ss, buf, ',')) v.push_back(buf);
    }
    bool isValidPreorder(int &idx){
        bool size_check = (idx==0)? true : false;
        if(idx>=v.size()) return false;
        else if(v[idx]=="#") {
            if(size_check && idx+1!=v.size()) return false;
            return true;
        }
        return isValidPreorder(++idx)&&isValidPreorder(++idx)&&(!size_check || size_check&&v.size()==idx+1);
    }
    bool isValidSerialization(string preorder) {
        int idx=0;
        parsing(preorder);
        return isValidPreorder(idx);
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int idx=0;
        for(int &push : pushed){
            st.push_back(push);
            while(idx<popped.size() && !st.empty() && st.back()==popped[idx]) {++idx; st.pop_back();}
        }
        return idx==popped.size();
    }
};
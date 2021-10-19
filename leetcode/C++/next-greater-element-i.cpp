class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        stack<int> st;
        vector<int> sol;
        for(int &n : nums2){
            while(!st.empty() && st.top()<n){ um[st.top()]=n; st.pop();}
            st.push(n);
        }
        while(!st.empty()){ um[st.top()]=-1; st.pop();}
        for(int &n : nums1) sol.push_back(um[n]);
        return sol;
    }
};
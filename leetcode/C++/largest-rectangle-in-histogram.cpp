class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sol = 0;
        vector<int> v(heights.size(),0);
        stack<int> st;
        for(int i=0; i<heights.size(); ++i){
            while(!st.empty() && heights[st.top()]>heights[i]){v[st.top()]=i-st.top(); st.pop();}
            st.push(i);
        }
        for(; !st.empty(); st.pop()) v[st.top()]=heights.size()-st.top();
        for(int i=(int)heights.size()-1; i>=0; --i){
            while(!st.empty() && heights[st.top()]>heights[i]) {v[st.top()]+=(st.top()-i-1); st.pop();}
            st.push(i);
        }
        for(; !st.empty(); st.pop()) v[st.top()]+=st.top();
        for(int i=0; i<heights.size(); ++i) sol=max(sol, v[i]*heights[i]);
        return sol;
    }
};
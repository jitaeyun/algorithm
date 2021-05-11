class Solution {
public:
    int trap(vector<int>& height) {
        int sol=0,i=0,t;
        stack<int> st;
        for(i=0; i<height.size(); ++i) if(height[i]) break;
        for(; i<height.size(); ++i){
            while(!st.empty() && height[st.top()]<=height[i]){
                t=st.top(); st.pop();
                if(!st.empty()){
                    sol+=(min(height[st.top()],height[i])-height[t])*(i-st.top()-1);
                }
            }
            st.push(i);
        }
        return sol;
    }
};
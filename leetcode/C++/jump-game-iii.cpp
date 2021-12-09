class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int idx=start;
        stack<int> st;
        st.push(idx);
        while(!st.empty()){
            idx=st.top(); st.pop();
            if(idx <0 || idx>=(int)arr.size() || arr[idx]<0) continue;
            else if(arr[idx]==0) return true;
            st.push(idx+arr[idx]);
            st.push(idx-arr[idx]);
            arr[idx]=-arr[idx];
        }        
        return false;
    }
};
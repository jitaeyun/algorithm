class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> sol={"JFK"};
        vector<int> visited(tickets.size(),0);
        stack<int> st;
        int s=0,t=-1;
        sort(tickets.begin(),tickets.end());
        while(st.size()<tickets.size()){
            s=0;
            for(int i=0; i<tickets.size(); ++i){
                if(visited[i] || i<=t) continue;
                if(tickets[i][0]==sol.back()){
                    visited[i]=s=1; t=-1;
                    sol.push_back(tickets[i][1]);
                    st.push(i);
                    break;
                }
            }
            if(s==0 && st.size()<tickets.size()) {
                t=st.top(); st.pop(); 
                visited[t]=0; sol.pop_back();
            }
        }
        return sol;
    }
};
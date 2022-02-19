class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn=1000000001, sol=1000000001, mx=0;
        priority_queue<int> pq;
        for(int &n : nums){
            if(n&1) n*=2;
            mn=min(mn, n);
            pq.push(n);
        }
        while(!pq.empty()){
            mx=pq.top(); pq.pop(); sol=min(sol, mx-mn); 
            if(mx&1) break;
            mx/=2; mn=min(mn, mx); pq.push(mx);
        }
        return sol;
    }
};
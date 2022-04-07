class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int a=0,b=0;
        for(int &s : stones) pq.push(s);
        while(pq.size() > 1){
            a=pq.top(); pq.pop(); b=pq.top(); pq.pop();
            if(a>b) pq.push(a-b);
        }
        return (pq.empty())? 0 : pq.top();
    }
};
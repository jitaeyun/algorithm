class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        priority_queue<int> pq;
        int cur = heights[0], t;
        for(int i=1; i<heights.size(); cur=heights[i++]){
            t=heights[i]-cur;
            if(t>0) {
                pq.push(t);
                b-=t;
                for(; b<0 && l>0; --l,pq.pop()){b+=pq.top();}
                if(b<0) return i-1;
            }
        }
        return heights.size()-1;
    }
};
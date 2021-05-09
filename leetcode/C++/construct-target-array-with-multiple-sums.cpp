class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1) return target[0]==1;
        long long curSum=0,prevSum=0,prevNum=0,n;
        priority_queue<int> pq(target.begin(),target.end());
        for(int &t: target) curSum+=t;
        while(!pq.empty()){
            prevSum=pq.top(); pq.pop();
            if(prevSum<=1) break;
            // subtract count until nextPrevSum
            n=(prevSum-pq.top())/(curSum-prevSum);
            // minimum n=1
            if(n<=0) n=1;
            // find previous number
            prevNum=prevSum-(curSum-prevSum)*n;
            // check if previous number is less than 1
            if(prevNum<1) return false;
            pq.push(prevNum);
            // update current sum
            curSum=curSum-prevSum+prevNum;
        }
        return prevSum==1;
    }
};
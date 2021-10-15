class Solution {
public:
    int no[2],buy[2],sell[2],keep[2];
    void swaps(){
        buy[0]=buy[1];
        sell[0]=sell[1];
        keep[0]=keep[1];
    }
    void init(int &p){
        buy[0]=-p;
        sell[0]=0;
        keep[0]=0;
    }
    void update(int &p){
        buy[1]=max(buy[0],-p);
        buy[1]=max(buy[1],keep[0]-p);
        keep[1]=max(keep[0],sell[0]);
        sell[1]=buy[0]+p;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int sol=0;
        init(prices[0]);
        for(int i=1; i<prices.size(); ++i){
            update(prices[i]);
            swaps();
        }
        return max(sell[1],keep[1]);
    }
};
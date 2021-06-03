class Solution {
public:
    const int mod = (1e9)+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long hd=0, vd=0, hp=0, vp=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int &t : horizontalCuts){
            hd=max(hd,t-hp);
            hp=t;
        }
        for(int &t : verticalCuts){
            vd=max(vd,t-vp);
            vp=t;
        }
        return hd*vd%mod;
    }
};
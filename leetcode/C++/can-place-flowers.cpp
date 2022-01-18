class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sol = 0;
        for(int i=0; i<flowerbed.size(); ++i){
            if((i==0 || flowerbed[i-1] == 0) && (flowerbed[i]==0) && (i+1 == flowerbed.size() || flowerbed[i+1] == 0) ) {++sol; flowerbed[i]=1;}
        }
        return sol>=n;
    }
};
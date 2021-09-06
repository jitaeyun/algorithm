class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int idx=0;
        for(int i=0,p=0,c=0,m=0; i<releaseTimes.size(); p=releaseTimes[i++]){
            if((c=releaseTimes[i]-p)>m || (c==m && keysPressed[i]>keysPressed[idx])){
                m=c;
                idx=i;
            }
        }
        return keysPressed[idx];
    }
};
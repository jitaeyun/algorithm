class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sol = 0;
        sort(people.begin(), people.end());
        for(int l=0, r=(int)people.size()-1, cur=0; l<=r; ++sol){
            cur = 0;
            if(l<=r && cur+people[r]<=limit) cur+=people[r--];
            if(l<=r && cur+people[l]<=limit) cur+=people[l++];
        }
        return sol;
    }
};
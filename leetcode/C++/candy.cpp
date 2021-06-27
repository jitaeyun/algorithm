class Solution {
public:
    int candy(vector<int>& ratings) {
        int sol=0;
        vector<int> v(ratings.size(),1);
        for(int i=1; i<ratings.size(); ++i){
            if(ratings[i-1]<ratings[i]) v[i]=v[i-1]+1;
        }
        sol=v.back();
        for(int i=(int)ratings.size()-2; i>=0; --i) {
            if(ratings[i]>ratings[i+1]) if (v[i]<v[i+1]+1) v[i]=v[i+1]+1;
            sol+=v[i];
        }
        return sol;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sol = 0;
        for(int l=0,r=(int)height.size()-1; l<=r;){
            sol = max(sol, min(height[l], height[r])*(r-l));
            (height[l]<height[r])? ++l : --r;
        }
        return sol;
    }
};


/*
// another solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sol=0,r=0;
        vector<int> v;
        for(int i=0; i<height.size(); ++i){
            if(!v.empty() && height[v.back()]<height[i]) v.push_back(i);
            else if(v.empty()) v.push_back(i);
        }
        for(int i=(int)height.size()-1,l=0; i>=0 && l<v.size(); --i){
            if(r<height[i]) {
                r=height[i];
                while(l<v.size() && height[v[l]]<=height[i]) {
                    sol=max(sol, height[v[l]]*(i-v[l]));
                    ++l;
                }
                if(l<v.size()) sol=max(sol, height[i]*(i-v[l]));
            }
            
        }
        return sol;
    }
};
*/
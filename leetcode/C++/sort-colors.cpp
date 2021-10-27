class Solution {
public:
    void sortColors(vector<int>& nums) {
        return stable_sort(nums.begin(),nums.end());
    }
};


/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for(int &n : nums) ++v[n];
        for(int i=0,k=0; i<v.size(); ++i){
            for(int j=0; j<v[i]; ++j){
                nums[k++]=i;
            }
        }
    }
};
*/
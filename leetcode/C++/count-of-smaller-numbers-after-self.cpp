class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int OFFSET=10001, count=0;
        vector<int> arr(20002,0);
        for(int i=(int)nums.size()-1; i>=0; --i){
            count=0;
            for(int j=nums[i]+OFFSET-1; j>0; j-=(j&(-j))) count+=arr[j];
            for(int j=nums[i]+OFFSET; j<20002; j+=(j&(-j))) ++arr[j];
            nums[i]=count;
        }
        return nums;
    }
};
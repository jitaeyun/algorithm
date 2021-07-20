class Solution {
public:
    Solution(vector<int>& nums) : nums(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> v = nums;
        random_device rd;
        mt19937 g(rd());
        std::shuffle(v.begin(), v.end(), g);
        return v;
    }
private:
    const vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
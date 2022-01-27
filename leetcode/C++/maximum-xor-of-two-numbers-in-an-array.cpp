class TRIE {
public:
    int count, val;
    TRIE* n;
    TRIE(){n = nullptr; count=val=0;}
    void makeTrie(){n = new TRIE[2];}
    void insertNode(int &max_bit, int &num){
        TRIE *r = this;
         for(int i=max_bit,bit=0; i>0; i>>=1){
            bit = (i&num)? 1 : 0; 
            if(r->n==nullptr) r->makeTrie();
            r = &(r->n[bit]);
            ++(r->count); r->val = num;
        }
    }
};

class Solution {
public:
    int find_max_bit(int &num){
        int bit = (1<<30);
        for(int i=bit; i>0; i>>=1){if(num&i) return i;}
        return bit;
    }
    int findMaximumXOR(vector<int>& nums) {
        int sol = 0, max_bit = 0;
        TRIE *t = new TRIE(), *r = nullptr;
        for(int &n : nums) max_bit = max(max_bit, n);
        max_bit = find_max_bit(max_bit);
        for(int i=0; i<nums.size(); ++i) t->insertNode(max_bit, nums[i]);
        for(int i=0,idx=0; i<nums.size(); ++i){
            if(nums[i]<max_bit) continue;
            r = t;
            for(int j=max_bit; j>0; j>>=1){
                idx = (j&nums[i])? 0 : 1;
                if(r->n[idx].count > 0) r=&(r->n[idx]);
                else r=&(r->n[idx^1]);
            }
            sol = max(sol, r->val^nums[i]);
        }
        return sol;
    }
};
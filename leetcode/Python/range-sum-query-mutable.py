class NumArray:

    def __init__(self, nums: List[int]):
        def _makeTree(idx, l , r):
            if l>=r:
                self.tree[idx] = nums[l]
                return nums[l]
            m = (l+r)//2
            self.tree[idx]=_makeTree(idx*2+1,l,m) + _makeTree(idx*2+2,m+1,r)
            return self.tree[idx]
        self.n = len(nums)
        self.tree = [0 for _ in range(len(nums)*4)]
        _makeTree(0,0,self.n-1)

    def update(self, index: int, val: int) -> None:
        def _treeUpdate(t_idx, l, r):
            if l>=r:
                diff,self.tree[t_idx] = val-self.tree[t_idx], val
                return diff
            m=(l+r)//2
            diff = _treeUpdate(t_idx*2+1,l,m) if index<=m else _treeUpdate(t_idx*2+2,m+1,r)
            self.tree[t_idx]+=diff
            return diff
        _treeUpdate(0,0,self.n-1)

    def sumRange(self, left: int, right: int) -> int:
        def _query(idx, l, r):
            if right<l or r<left:
                return 0
            if left<=l and right>=r:
                return self.tree[idx]
            m=(l+r)//2
            return _query(idx*2+1,l,m) + _query(idx*2+2,m+1,r)
        return _query(0,0,self.n-1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
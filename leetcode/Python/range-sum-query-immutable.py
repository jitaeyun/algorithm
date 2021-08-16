class NumArray:

    def __init__(self, nums: List[int]):
        self.v = list()
        for n in nums:
            if not self.v:
                self.v.append(n)
            else:
                self.v.append(self.v[-1]+n)

    def sumRange(self, left: int, right: int) -> int:
        return self.v[right] if left==0 else self.v[right]-self.v[left-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
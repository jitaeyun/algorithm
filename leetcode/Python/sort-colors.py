class Solution:
    def sortColors(self, nums: List[int]) -> None:
        nums.sort()
        return nums

'''
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        v,idx = [0]*3, 0
        for n in nums:
            v[n]+=1
        for i in range(len(v)):
            for j in range(v[i]):
                nums[idx], idx = i, idx+1
        
'''
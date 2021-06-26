class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        arr, OFFSET = [0 for _ in range(20002)], 10001
        res, n = 0, 0     
        for i in range(len(nums)-1,-1,-1):
            res, n = 0, nums[i]+OFFSET-1
            while n>0:
                res+=arr[n]
                n-=(n&(-n))
            n = nums[i]+OFFSET
            while n<len(arr):
                arr[n]+=1
                n+=(n&(-n))
            nums[i] = res
        return nums
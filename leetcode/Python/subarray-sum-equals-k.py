class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        um, s, sol = defaultdict(list), 0, 0
        um[0].append(len(nums))
        for i in range(len(nums)-1, -1, -1):
            s += nums[i]
            um[s].append(i)
        for i in range(len(nums)):
            idx = s - k
            l = um.get(idx, list())
            while len(l)>0 and i >= l[-1]:
                l.pop()
            sol += len(l)
            s -= nums[i]
        return sol
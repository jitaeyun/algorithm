class Solution:
    def trap(self, height: List[int]) -> int:
        l, sol = [], 0
        for i, h in enumerate(height):
            if not l:
                if h > 0:
                    l.append(i)
                continue
            while l and h>=height[l[-1]]:
                if len(l) > 1:
                    sol+=(min(h,height[l[-2]])-height[l[-1]])*(i-l[-2]-1)
                l.pop()
            l.append(i)
        return sol
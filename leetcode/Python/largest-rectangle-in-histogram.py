class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        sol, v, st = 0, [0]*len(heights), list()
        for i in range(len(heights)):
            while len(st)>0 and heights[st[-1]]>heights[i]:
                v[st[-1]] += i-st.pop()
            st.append(i)
        while len(st)>0:
            v[st[-1]] += len(heights) - st.pop()
        for i in range(len(heights)-1, -1, -1):
            while len(st) > 0 and heights[st[-1]] > heights[i]:
                v[st[-1]] += st.pop()-i-1
            st.append(i)
        while len(st)>0:
            v[st[-1]] += st.pop()
        for i in range(len(heights)):
            sol = max(sol, v[i]*heights[i])
        return sol
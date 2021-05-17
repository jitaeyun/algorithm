class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        sol, st = [0 for i in range(len(temperatures))], []
        for i, v in enumerate(temperatures):
            while st and temperatures[st[-1]]<v:
                sol[st.pop()]=i-st[-1]
            st.append(i)
        return sol
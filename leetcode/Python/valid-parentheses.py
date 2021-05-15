class Solution:
    def isValid(self, s: str) -> bool:
        st, d = [], {'(':')', '{':'}', '[':']'}
        for v in s:
            if v in d.keys():
                st.append(d[v])
            elif st and v==st[-1]:
                st.pop()
            else:
                return False
        return not st
import re
class Solution:
    def isValid(self, s: str) -> bool:
        st, d = [], {'(':')', '{':'}', '[':']'}
        for v in s:
            if re.search(r'[\(\[\{]', v):
                st.append(v)
            elif st and d[st[-1]]==v:
                st.pop()
            else:
                return False
        return True
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        st, val = [0], 0
        for ch in s:
            if ch == '(':
                st.append(0)
            else:
                val = st.pop()
                st[-1] += 2*val if val > 0 else 1
        return st[-1]
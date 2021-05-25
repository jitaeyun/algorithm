class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st, a, b = [], 0, 0
        for s in tokens:
            if s=='+':
                st.append(st.pop()+st.pop())
            elif s=='-':
                b, a = st.pop(), st.pop()
                st.append(a-b)
            elif s=='/':
                b, a = st.pop(), st.pop()
                st.append(int(a/b))
            elif s=='*':
                st.append(st.pop()*st.pop())
            else:
                st.append(int(s))
        return st.pop()
            
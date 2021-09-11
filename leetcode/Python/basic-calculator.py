class Solution:
    def calculate(self, s: str) -> int:
        def subcalculate():
            s, c, m = 0, None, 1
            while st and st[-1]!='(':
                tst.append(st.pop())
            if st and st[-1]=='(':
                st.pop()
            while tst:
                c = tst.pop()
                if c == '-':
                    m = -1
                elif c == '+':
                    m = 1
                else:
                    s+=(c*m)
            st.append(s)
        st, tst, num = [], [], 0
        for i,c in enumerate(s):
            if c==' ':
                continue
            elif c=='+' or c=='-' or c=='(':
                st.append(c)
            elif '0'<=c<='9':
                num = num*10 + int(c)
                if i+1==len(s) or not ('0'<=s[i+1]<='9'):
                    st.append(num)
                    num=0
            else:
                subcalculate()
        subcalculate()
        return st.pop()
            
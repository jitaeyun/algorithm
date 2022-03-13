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


'''
class Solution:
    def isValid(self, s: str) -> bool:
        um, st = {'(': ')', '{': '}', '[':']'}, list()
        for ch in s:
            t = um.get(ch, None)
            if t is not None:
                st.append(t)
            elif len(st)>0 and st[-1] == ch:
                st.pop()
            else:
                return False
        return len(st) == 0
'''
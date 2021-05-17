class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        st, flag, t = [], set(), 0
        fre = collections.Counter(s)
        for ch in s:
            fre[ch]-=1
            if ch in flag:
                continue
            while st and st[-1]>ch and fre[st[-1]]>0:
                flag.remove(st.pop())
            st.append(ch)
            flag.add(ch)
        return "".join(st)
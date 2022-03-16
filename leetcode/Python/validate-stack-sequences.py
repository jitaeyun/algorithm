class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st, idx = list(), 0
        for push in pushed:
            st.append(push)
            while idx<len(popped) and len(st)>0 and st[-1]==popped[idx]:
                idx += 1
                st.pop()
        return idx == len(popped)
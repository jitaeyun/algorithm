class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        st, idx = [start], 0
        while st:
            idx = st.pop()
            if idx < 0 or idx >= len(arr) or arr[idx] < 0:
                continue
            elif arr[idx] == 0:
                return True
            st.append(idx+arr[idx])
            st.append(idx-arr[idx])
            arr[idx] = -arr[idx]
        return False
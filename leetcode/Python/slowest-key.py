class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        idx, c, p, m = 0, 0, 0, 0
        for i, r in enumerate(releaseTimes):
            if (c:=r-p) > m or (c == m and keysPressed[i] > keysPressed[idx]):
                idx, m = i, c
            p = r
        return keysPressed[idx]
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        shift, sol = 0, []
        for i in range(len(shifts)):
            shifts[i]%=26
            shift=(shift+shifts[i])%26
        for i in range(len(shifts)):
            idx, shift = (ord(s[i])-ord('a') + shift)%26,shift-shifts[i]
            sol.append(chr(ord('a')+idx))
            if shift < 0:
                shift+=26
        return ''.join(sol)
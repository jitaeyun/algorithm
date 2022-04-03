class Solution:
    def validPalindrome(self, s: str) -> bool:
        i, j, a, b = 0, len(s)-1, 0, 0
        while i<j:
            if s[i]!=s[j]:
                break
            i, j = i + 1 , j - 1
        a, b = i + 1 , j
        while a<b:
            if s[a]!=s[b]:
                break
            a, b = a + 1, b - 1
        if a>=b:
            return True
        a, b = i, j - 1
        while a<b:
            if s[a]!=s[b]:
                break
            a, b = a + 1, b - 1
        return a>=b
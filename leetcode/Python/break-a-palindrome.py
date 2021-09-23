class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        solved, i, j, s = False, 0, len(palindrome)-1, list(palindrome)
        while i<j:
            if s[i]!='a':
                s[i], solved = 'a', True
                palindrome = ''.join(s)
                break
            i, j = i+1, j-1
        if len(s)<=1:
            palindrome=''
        elif not solved:
            s[-1]='b'
            palindrome = ''.join(s)
        return palindrome
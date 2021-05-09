class Solution:
    def isPalindrome(self, s: str) -> bool:
        ts = re.findall('[a-zA-Z0-9]', s.lower())
        return ts == ts[::-1]
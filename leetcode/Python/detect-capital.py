class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        upperLen = 0
        for w in word:
            if 'A'<=w<='Z':
                upperLen += 1
        return (upperLen == len(word)) or (upperLen == 0) or (upperLen == 1 and 'A'<=word[0]<='Z')
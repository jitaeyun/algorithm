class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        pSum=sum(cardPoints[-k:])
        sol=pSum
        for i in range(k):
            pSum=pSum+cardPoints[i]-cardPoints[i-k]
            sol=max(sol,pSum)
        return sol
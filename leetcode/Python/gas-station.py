class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        m, s, j = 0, 0, 0
        for i in range(len(gas)):
            s, j = s+gas[i]-cost[i], j+gas[i]-cost[i]
            if j<gas[i]-cost[i]:
                m, j = i, gas[i]-cost[i]
        return m if s>=0 else -1
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        l = collections.defaultdict(list)
        for s in strs:
            l[''.join(sorted(s))].append(s)
        return [s for s in l.values()]
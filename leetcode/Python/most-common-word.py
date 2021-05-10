class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        d = collections.defaultdict(int)
        for s in re.sub('[^\w]', ' ', paragraph.lower()).split():
            if s not in banned:
                d[s]+=1
        return max(d, key=d.get)
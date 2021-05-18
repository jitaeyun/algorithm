class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        t, d, sol, m = 0, "", [], collections.defaultdict(list)
        for path in paths:
            for i, s in enumerate(path.split()):
                if i==0:
                    d=s
                else:
                    t=s.find("(")
                    m[s[t:]].append(d+'/'+s[:t])
        for _, v in m.items():
            if len(v) > 1:
                sol.append(v)
        return sol
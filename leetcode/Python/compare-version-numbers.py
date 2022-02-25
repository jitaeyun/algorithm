class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def versionParsing(version: str):
            v, s = list(), ''
            for ch in version:
                if ch == '.':
                    if len(s)>0:
                        v.append(int(s))
                    s = ''
                else:
                    s += ch
            if len(s)>0:
                v.append(int(s))
            return v
        v1, v2 = versionParsing(version1), versionParsing(version2)
        idx_1, idx_2 = 0, 0
        while idx_1<len(v1) and idx_2<len(v2):
            if v1[idx_1]>v2[idx_2]:
                return 1
            elif v1[idx_1]<v2[idx_2]:
                return -1
            idx_1, idx_2 = idx_1 + 1 , idx_2 + 1
        while idx_1<len(v1):
            if v1[idx_1] > 0:
                return 1
            idx_1 += 1
        while idx_2 < len(v2):
            if v2[idx_2] > 0:
                return -1
            idx_2 += 1
        return 0
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        um, rum = dict(), dict()
        ps = s.split(' ')
        if len(ps) != len(pattern):
            return False
        for i in range(len(ps)):
            v = um.get(pattern[i], None)
            rv = rum.get(ps[i], None)
            if v is None:
                v = um[pattern[i]] = ps[i]
            if rv is None:
                rv = rum[ps[i]] = pattern[i]
            if v != ps[i] or rv != pattern[i]:
                return False
        return True
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        group, sol, t, um = [0], list(), [list() for _ in range(len(accounts))], dict()
        def find(a):
            if group[a]==0:
                return a
            group[a]=find(group[a])
            return group[a]
        def unions(a, b):
            a, b = find(a), find(b)
            if a==b:
                return
            elif a<b:
                group[b]=a
            else:
                group[a]=b
        for i in range(len(accounts)):
            group.append(0)
            for j in range(1,len(accounts[i])):
                st = accounts[i][0]+'+'+accounts[i][j]
                val = um.get(st, None)
                if val is None:
                    um[st]=i+1
                else:
                    unions(i+1, val)
        for i in range(len(accounts)):
            for j in range(1,len(accounts[i])):
                st = accounts[i][0]+'+'+accounts[i][j]
                val = um.get(st,None)
                if val is None or val == -1:
                    continue
                t[find(val)-1].append(accounts[i][j])
                um[st]=-1
        for i in range(len(t)):
            if len(t[i]) == 0:
                continue
            t[i].sort()
            sol.append([accounts[i][0]]+t[i])
        return sol
                    
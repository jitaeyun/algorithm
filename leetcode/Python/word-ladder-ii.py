class Solution:
    def __init__(self):
        self.paths = []
        self.sol = []
    def transform(self, a, b):
        c = 0
        if len(a)!=len(b):
            return False
        for i in range(len(a)):
            if a[i]!=b[i]:
                c+=1
            if c>1:
                return False
        return True if c==1 else False
    def makePaths(self, wordList):
        self.paths = [[] for i in range(len(wordList))]
        for i in range(len(wordList)):
            for j in range(i+1,len(wordList)):
                if self.transform(wordList[i], wordList[j]):
                    self.paths[i].append(j)
                    self.paths[j].append(i)
    def findPaths(self, beginWord, endWord, wordList):
        dq, visit, sol_paths = collections.deque(), [0]*len(wordList), []
        idx, end_idx, s, e = 0, -1, 0, 0
        for i in range(len(wordList)):
            if self.transform(wordList[i], beginWord):
                dq.append(i)
                visit[i]=1
            if endWord == wordList[i]:
                end_idx=i
        if end_idx == -1:
            return
        while len(dq)>0:
            idx=dq.popleft()
            if visit[end_idx]>0 and visit[idx] > visit[end_idx]:
                break
            for next_idx in self.paths[idx]:
                if visit[next_idx] > 0:
                    continue
                dq.append(next_idx)
                visit[next_idx]=visit[idx]+1
        if visit[end_idx]==0:
            return
        sol_paths.append([end_idx])
        while visit[sol_paths[-1][-1]] > 1:
            e = len(sol_paths)
            for i in range(s,e):
                idx = sol_paths[i][-1]
                for next_idx in self.paths[idx]:
                    if visit[next_idx] +1 == visit[idx]:
                        sol_paths.append(sol_paths[i][:])
                        sol_paths[-1].append(next_idx)
            s = e
        for i in range(s,len(sol_paths)):
            t = [beginWord]
            for j in range(len(sol_paths[i])-1,-1,-1):
                t.append(wordList[sol_paths[i][j]])
            self.sol.append(t)
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        self.makePaths(wordList)
        self.findPaths(beginWord, endWord, wordList)
        return self.sol
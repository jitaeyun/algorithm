class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        um, dq, ed = defaultdict(list), collections.deque(), -1
        visit = [0]*(len(wordList)+1)
        wordList.append(beginWord)
        for i, word in enumerate(wordList):
            if ed == -1 and endWord == word:
                ed = i
            for j in range(len(word)):
                um[word[:j] + '.' + word[j+1:]].append(i)
        visit[-1] = 1
        dq.append(len(visit)-1)
        if ed < 0:
            return 0
        while len(dq) > 0:
            idx = dq.popleft()
            if idx == ed:
                return visit[idx]
            for i in range(len(wordList[idx])):
                for n in um[wordList[idx][:i] + '.' + wordList[idx][i+1:]]:
                    if idx != n and visit[n] == 0:
                        visit[n] = visit[idx] + 1
                        dq.append(n)
        return 0
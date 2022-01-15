class Solution:
    def minJumps(self, arr: List[int]) -> int:
        visit, um, dq = [-1]*len(arr), defaultdict(list), collections.deque()
        cur_idx, next_idx, d_idx = 0, 0, [-1, 1]
        for k, v in enumerate(arr):
            um[v].append(k)
        dq.append(0)
        visit[0] = 0
        while dq:
            cur_idx = dq.popleft()
            if cur_idx + 1 == len(arr):
                return visit[cur_idx]
            for d in d_idx:
                next_idx = cur_idx + d
                if next_idx < 0 or next_idx >= len(arr) or visit[next_idx] > -1:
                    continue
                dq.append(next_idx)
                visit[next_idx] = visit[cur_idx] + 1
            v = um[arr[cur_idx]]
            for i in range(len(v)-1, -1, -1):
                next_idx = v[i]
                if visit[next_idx] == -1:
                    dq.append(next_idx)
                    visit[next_idx] = visit[cur_idx] + 1
                v.pop()
        return visit[-1]
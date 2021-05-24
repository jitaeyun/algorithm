class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        p, c, sol, st, node, t = [[] for i in range(numCourses)], [[] for i in range(numCourses)], [], [], 0, 0
        for pre in prerequisites:
            p[pre[0]].append(pre[1])
            c[pre[1]].append(pre[0])
        for i in range(numCourses):
            if not p[i]:
                st.append(i)
        while st:
            node=st.pop()
            sol.append(node)
            for n in c[node]:
                t=p[n].index(node)
                p[n][t], p[n][-1] = p[n][-1], p[n][t]
                p[n].pop()
                if not p[n]:
                    st.append(n)
        return len(sol)==numCourses
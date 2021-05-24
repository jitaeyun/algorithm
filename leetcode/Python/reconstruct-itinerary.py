class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        sol, st, f, v, t = ["JFK"], [], 0, [0 for i in range(len(tickets))], -1
        tickets.sort()
        while len(st) < len(tickets):
            f=0
            for i in range(len(tickets)):
                if v[i]>0 or i<=t:
                    continue
                if tickets[i][0]==sol[-1]:
                    sol.append(tickets[i][1])
                    st.append(i)
                    t, f, v[i] = -1, 1, 1
                    break;
            if f==0:
                t=st.pop()
                sol.pop()
                v[t]=0
        return sol
                
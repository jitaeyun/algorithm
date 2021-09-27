class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        us, idx = set(), 0
        for e in emails:
            ln = list()
            idx = e.find('@')
            for i in range(idx):
                if e[i]=='.':
                    continue
                elif e[i]=='+':
                    break
                ln.append(e[i])
            us.add('{}{}'.format(''.join(ln),e[idx:]))
        return len(us)
                
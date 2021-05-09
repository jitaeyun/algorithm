class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        ll, dl = [], []
        for log in logs:
            if log.split()[1].isdigit():
                dl.append(log)
            else:
                ll.append(log)
        ll.sort(key = lambda x: (x.split()[1:], x.split()[0]))
        return ll + dl
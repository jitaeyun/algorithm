class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        sol , l, r, cur = 0, 0, len(people)-1, 0
        people.sort()
        while l<=r:
            cur = 0
            if l<=r and people[r]+cur<=limit:
                cur, r = cur + people[r], r - 1
            if l<=r and people[l]+cur<=limit:
                cur, l = cur + people[l], l + 1
            sol += 1
        return sol
class Solution:
    def candy(self, ratings: List[int]) -> int:
        v = [1]*len(ratings)
        for i in range(len(ratings)-1):
            if ratings[i]<ratings[i+1]:
                v[i+1]=v[i]+1
        for i in range(len(ratings)-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                v[i]=max(v[i+1]+1,v[i])
        return sum(v)
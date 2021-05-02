from queue import PriorityQueue
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        cur, pq = 0, PriorityQueue()
        for course in sorted(courses, key= lambda x: x[1]):
            cur+=course[0]
            pq.put(-course[0])
            if cur > course[1]:
                cur+=pq.get()
        return pq.qsize()
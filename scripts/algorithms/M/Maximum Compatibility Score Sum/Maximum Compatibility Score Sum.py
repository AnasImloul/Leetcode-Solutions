# Runtime: 104 ms (Top 82.18%) | Memory: 13.9 MB (Top 66.34%)
import heapq
from collections import defaultdict

class Solution:
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        m, n = len(students), len(students[0])
        def hamming(student, mentor):
            return sum([int(student[i] != mentor[i]) for i in range(n)])

        pq = [(0, 0, '0'*m)] # state: (n-comp_score aka Hamming distance, number of assigned students, mentor status)
        optimal = defaultdict(lambda:float('inf'))

        while pq: # O(V)
            cost, i, mentor_status = heapq.heappop(pq) # O(logV)

            # early stopping with termination condition
            if i == m:
                return m * n - cost

            # generate successors. The next student to be assigned is at index i
            for j, mentor in enumerate(mentors): # O(m)
                if mentor_status[j] != '1':
                    new_cost = cost + hamming(students[i], mentor)
                    new_mentor_status = mentor_status[:j] + '1' + mentor_status[j+1:]

                    # update optimal cost if a new successor appears with lower cost to the same node
                    if new_cost < optimal[(i+1, new_mentor_status)]:
                        optimal[(i+1, new_mentor_status)] = new_cost
                        heapq.heappush(pq, (new_cost, i+1, new_mentor_status)) # O(logV)

        return 0
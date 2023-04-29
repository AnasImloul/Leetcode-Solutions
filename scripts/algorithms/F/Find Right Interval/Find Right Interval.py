class Solution:
    def findRightInterval(self, A: List[List[int]]) -> List[int]:
        n = len(A)
        ans = [-1] * n

        for i in range(n):
            A[i].append(i)

        A.sort()
        heap = []

        for i in range(n):
            if A[i][0] == A[i][1]:
                ans[A[i][2]] = A[i][2]
            else:
                while heap and heap[0][0] <= A[i][0]:
                    ans[heapq.heappop(heap)[1]] = A[i][2]
                
                heapq.heappush(heap, [A[i][1], A[i][2]])

        return ans
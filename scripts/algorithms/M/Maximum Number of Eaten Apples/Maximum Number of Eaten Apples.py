from heapq import heappush, heappop
class Solution:
    def eatenApples(self, A: List[int], D: List[int]) -> int:
        ans, i, N = 0, 0, len(A)
        h = []
        while i < N or h:
            # only push to heap when you have a valid i, and the apple has atleast one day to stay fresh.
            if i<N and A[i] > 0:
                heappush(h, [i+D[i], A[i]])
            # remove the rotten apples batches and the batches with no apples left (which might have got consumed).
            while h and (h[0][0] <= i or h[0][1] <= 0):
                heappop(h)
            # only if there is batch in heap after removing all the rotten ones, you can eat. else wait for the subsequent days for new apple batch by incrementing i.
            if h:
                h[0][1]-=1
                ans+=1
            i+=1
        return ans 

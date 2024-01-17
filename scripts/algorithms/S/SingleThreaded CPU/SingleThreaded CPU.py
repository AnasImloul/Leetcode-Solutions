// Runtime: 1435 ms (Top 91.03%) | Memory: 66.80 MB (Top 7.59%)

class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        
        heap, prev, ans = [], 0, []

        tasks = sorted((task,i) for i,task in enumerate(tasks))
        
        for (enq, pro), i in tasks:

            while heap and prev < enq:

                proj, j, enqj = heappop(heap)
                prev = max(enqj, prev) + proj
                ans.append(j)

            heappush(heap, (pro, i, enq))

        return ans+[i for _, i, _ in sorted(heap)] 


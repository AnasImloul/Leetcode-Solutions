// Runtime: 741 ms (Top 85.29%) | Memory: 92.40 MB (Top 82.35%)

class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        
        def pathSum(node, n):

            visited.add(node)
            prefixSum.append(prefixSum[-1] + node)

            #Find maxSum from this node
            if k > n:
                count = k - n
                summa = cycleSum * (count // cycleLen)
                summa += prefixSum[-1] - prefixSum[-(count % cycleLen + n+2)]
                self.maxi = max(self.maxi, summa)
            else:
                self.maxi = max(self.maxi, prefixSum[-1] - prefixSum[-k-2])

            #DFS
            for item in reversedAdj[node]:
                pathSum(item, n+1)
            prefixSum.pop()

        #Build reversed adj
        reversedAdj = defaultdict(list)
        for i, j in enumerate(receiver):
            reversedAdj[j].append(i)

        self.maxi = 0
        visited = set()

        #Iterate through the graph
        for node in receiver:
            if not node in visited:

                #Find a node from cycle                
                while not node in visited:
                    visited.add(node)
                    node = receiver[node]
                
                #Initialize prefixSum
                start = node
                prefixSum = [0, -node]
                while receiver[node] != start:
                    node = receiver[node]
                    prefixSum.append(prefixSum[-1] - node)

                prefixSum.reverse()
                cycleSum = -prefixSum[0]
                cycleLen = len(prefixSum) - 1
                reversedAdj[start].remove(node)

                pathSum(node, 0)

        return self.maxi

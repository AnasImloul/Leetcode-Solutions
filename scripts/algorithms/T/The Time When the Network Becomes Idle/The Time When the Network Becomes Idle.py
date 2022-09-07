# Runtime: 2578 ms (Top 92.45%) | Memory: 69.3 MB (Top 19.78%)
class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:

        #Build Adjency List
        adjList = defaultdict(list)

        for source, target in edges:
            adjList[source].append(target)
            adjList[target].append(source)

        #BFS to get the shortest route from node to master.
        shortest = {}
        queue = deque([(0,0)])
        seen = set()
        while queue:
            currPos, currDist = queue.popleft()

            if currPos in seen:
                continue
            seen.add(currPos)
            shortest[currPos] = currDist

            for nei in adjList[currPos]:
                queue.append((nei, currDist+1))

        #Calculate answer using shortest paths.
        ans = 0
        for index in range(1,len(patience)):
            resendInterval = patience[index]

            #The server will stop sending requests after it's been sent to the master node and back.
            shutOffTime = (shortest[index] * 2)

            # shutOffTime-1 == Last second the server can send a re-request.
            lastSecond = shutOffTime-1

            #Calculate the last time a packet is actually resent.
            lastResentTime = (lastSecond//resendInterval)*resendInterval

            # At the last resent time, the packet still must go through 2 more cycles to the master node and back.
            lastPacketTime = lastResentTime + shutOffTime

            ans = max(lastPacketTime, ans)

        #Add +1, the current answer is the last time the packet is recieved by the target server (still active).
        #We must return the first second the network is idle, therefore + 1
        return ans + 1
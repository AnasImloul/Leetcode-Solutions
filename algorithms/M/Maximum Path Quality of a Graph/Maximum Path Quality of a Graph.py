class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        graph = defaultdict(list)
		# build graph
        for edge in edges:
            graph[edge[0]].append((edge[1], edge[2]))
            graph[edge[1]].append((edge[0], edge[2]))
        
        q = deque()
        q.append((0, 0, values[0], set([0])))
        cache = {}
        maxPoint = 0
		
        while q:
            currV, currTime, currPoints, currSet = q.popleft()
            if currV in cache:
				# if vertex has been visited, and if the previousTime is 
				# less or equal to current time but current points is lower?
				# then this path can't give us better quality so stop proceeding.
                prevTime, prevPoints = cache[currV]
                if prevTime <= currTime and prevPoints > currPoints:
                    continue
            cache[currV] = (currTime, currPoints)
			# can't go over the maxTime limit
            if currTime > maxTime:
                continue
			# collect maxPoint only if current vertex is 0
            if currV == 0:
                maxPoint = max(maxPoint, currPoints)
            for neigh, neighTime in graph[currV]:
                newSet = currSet.copy()
				# collects quality only if not collected before
                if neigh not in currSet:
                    newSet.add(neigh)
                    newPoint = currPoints + values[neigh]
                else:
                    newPoint = currPoints
                q.append((neigh, currTime + neighTime, newPoint, newSet))
        return maxPoint

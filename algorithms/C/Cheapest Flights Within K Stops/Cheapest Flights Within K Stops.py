class Solution:
	def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
		graph = defaultdict(list)
		for u,v,w in flights: graph[u].append((v,w))

		pq = [(0,src,0)]
		dis = [float('inf')]*n

		while pq:
			c,n,l = heappop(pq)
			if n==dst: return c
			if l > k or l>= dis[n]: continue
			dis[n] = l
			for v,w in graph[n]:
				heappush(pq,(c+w,v,l+1))
		return -1

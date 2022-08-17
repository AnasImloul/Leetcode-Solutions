class Solution:
	def longestDiverseString(self, a: int, b: int, c: int) -> str:
		pq = []
		if a > 0: heapq.heappush(pq,(-a,'a'))        
		if b > 0: heapq.heappush(pq,(-b,'b'))        
		if c > 0: heapq.heappush(pq,(-c,'c'))

		ans = ''
		while pq:
			c, ch = heapq.heappop(pq)
			if len(ans)>1 and ans[-1] == ans[-2] == ch:
				if not pq: break
				c2, ch2 = heapq.heappop(pq)
				ans += ch2
				c2 += 1
				if c2: heapq.heappush(pq,(c2,ch2))
			else:
				ans += ch
				c += 1
			if c: heapq.heappush(pq,(c,ch))

		return ans

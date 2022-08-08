class Solution:
	def reorganizeString(self, s: str) -> str:
		c = Counter(s)  # for counting the distinct element 
		pq = []
		for k,v in c.items(): heapq.heappush(pq,(-v,k))  #multipy by -1 to make max heap 
		ans = ''
		while pq :
			c, ch = heapq.heappop(pq)
			if ans and ans[-1] == ch: 
				if not pq: return '' // if heap is empty we cant make the ans return empty string
				c2, ch2 = heapq.heappop(pq)
				ans += ch2
				c2 += 1
				if c2: heapq.heappush(pq,(c2,ch2))
			else:
				ans += ch
				c += 1
			if c: heapq.heappush(pq,(c,ch))
		return ans
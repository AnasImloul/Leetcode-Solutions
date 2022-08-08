import queue
class Solution:
	def numOfMinutes(self, n: int, headID: int, manager: List[int],time: List[int]) -> int:
		nodes = []
		for i in range(n): nodes.append([])
		for i in range(n): 
			if i != headID: nodes[manager[i]].append(i)

		q = queue.LifoQueue()
		q.put([headID,0])
		ans = 0
		while not q.empty():
			cur = q.get()
			for nxt in nodes[cur[0]]:
				q.put([nxt,cur[1]+time[cur[0]]])
				ans = max(ans,cur[1]+time[cur[0]])
		return ans
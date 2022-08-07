class Heap:
	def __init__(self):
		self.q = []
	def push(self,data):
		i = len(self.q)
		self.q.append(data)
		while i>0:
			if self.q[i] > self.q[(i-1)//2]:
				self.q[i], self.q[(i-1)//2] = self.q[(i-1)//2], self.q[i]
				i = (i-1)//2
			else: return 
	def pop(self):
		if len(self.q)==0:return
		self.q[0] = self.q[-1]
		self.q.pop()
		def heapify(i):
			ind = i
			l = 2*i+1
			r = 2*i+2
			if r<len(self.q) and self.q[ind] < self.q[r]: ind = r
			if l<len(self.q) and self.q[ind] < self.q[l]: ind = l            
			if ind != i:
				self.q[i], self.q[ind] = self.q[ind], self.q[i]
				heapify(ind)
		heapify(0)
	def top(self):  
		return self.q[0] 


class Solution:
	def wiggleSort(self, nums: List[int]) -> None:
		n = len(nums)
		h = Heap()
		for i in nums: h.push(i)
		for i in range(1,n,2):
			nums[i] = h.top()
			h.pop()
		for i in range(0,n,2):
			nums[i] = h.top()
			h.pop()
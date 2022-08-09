class Solution:
	def findMaximumXOR(self, nums: List[int]) -> int:
		TrieNode = lambda: defaultdict(TrieNode)
		root = TrieNode()
		for n in nums:
			cur = root
			for i in range(31,-1,-1):
				bit = 1 if n&(1<<i) else 0
				cur = cur[bit]
			cur['val']=n

		ans = 0
		for n in nums:        
			cur = root
			for i in range(31,-1,-1):
				bit = 1 if n&(1<<i) else 0
				if bit == 1:
					if 0 in cur: cur = cur[0]
					else: cur = cur[1]
				else: 
					if 1 in cur: cur = cur[1]
					else: cur = cur[0]
			ans = max(ans,cur['val']^n)

		return ans
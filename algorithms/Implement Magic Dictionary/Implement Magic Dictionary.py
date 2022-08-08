class MagicDictionary:

	def __init__(self):
		TrieNode = lambda : defaultdict(TrieNode)
		self.root = TrieNode()

	def buildDict(self, dictionary: List[str]) -> None:
		for s in dictionary:
			cur = self.root
			for c in s: cur = cur[ord(c)-ord('a')]
			cur['$']=True

	def search(self, searchWord: str) -> bool:
		def find(i,cur,mis):
			if i==len(searchWord) and mis==0: return('$' in cur)
			if mis < 0: return False
			if i==len(searchWord) and mis!=0: return False
			ind = ord(searchWord[i])-ord('a')
			ans = False
			for j in range(26):
				if j in cur:
					if(j!=ind):
						ans |= find(i+1,cur[j],mis-1)
					else: ans |= find(i+1,cur[j],mis)
			return ans
			
		return find(0,self.root,1)

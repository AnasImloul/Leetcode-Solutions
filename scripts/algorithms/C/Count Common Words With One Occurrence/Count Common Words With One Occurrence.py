class Solution:
	def countWords(self, words1: List[str], words2: List[str]) -> int:
		count = Counter(words1 + words2)
		return len([word for word in count if count[word] == 2 and word in words1 and word in words2])

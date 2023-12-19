// Runtime: 46 ms (Top 6.11%) | Memory: 16.10 MB (Top 75.91%)

class Solution:
	def defangIPaddr(self, address: str) -> str:
		return address.replace('.', '[.]')

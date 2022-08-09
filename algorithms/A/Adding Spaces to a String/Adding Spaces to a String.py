#TLE SOLUTION
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
		spaces_idx = len(spaces)-1

		def addString(index,s):
			s = s[:index]+" "+s[index:] 
			#This changes the string at every instance hence taking so much time
			return s
			
		while spaces_idx>=0:
			s = addString(spaces[spaces_idx],s)
			spaces_idx-=1
		return s

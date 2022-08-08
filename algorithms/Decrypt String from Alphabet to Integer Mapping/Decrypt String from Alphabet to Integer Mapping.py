class Solution:
	def freqAlphabets(self, s: str) -> str:
		ans=""
		i=0
		while i<len(s):
			if i+2<len(s) and s[i+2]=="#":
				no=(int(s[i])*10)+(int(s[i+1]))
				ans+=chr(no+ord("a")-1)
				i+=3
			else:
				ans+=chr(int(s[i])+ord("a")-1)
				i+=1
		return ans
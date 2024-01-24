// Runtime: 932 ms (Top 96.15%) | Memory: 70.20 MB (Top 90.38%)

class Solution:
	def longestPalindrome(self, word1: str, word2: str) -> int:
		res=0
		new_word=word1+word2
		n,mid=len(word1)+len(word2),len(word1)
		dp=[[0]*n for _ in range(n)]
		for i in range(n):
			dp[i][i]=1
		for l in range(n-2,-1,-1):
			for r in range(l+1,n,1):
				if new_word[l]==new_word[r]:
					dp[l][r]=(dp[l+1][r-1] if r-1>=l+1 else 0)+2
					if l<mid and r>=mid:
						res=max(res,dp[l][r])
				else:
					dp[l][r]=max(dp[l+1][r],dp[l][r-1])
		return res
class Solution:
	def superPow(self, a: int, b: List[int]) -> int:
		mod = 1337
		ans = 1

		for power in b:
			ans  = ((pow(ans,10)%mod)*(pow(a,power)%mod))%mod

		return ans
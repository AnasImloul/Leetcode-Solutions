class Solution:
	def minCost(self, colors: str, neededTime: List[int]) -> int:
		n=len(colors)

		cur_sum=0
		i=0
		while i<n-1:
			if colors[i]==colors[i+1]:
				max_val=float("-inf")
				for j in range(i,n):
					max_val=max(max_val,neededTime[j])
					if j!=n-1 and colors[j]!=colors[j+1]:
						break
				cur_sum+=sum(neededTime[i:j+1])-max_val
				i=j+1
			else:
				i+=1
		return cur_sum
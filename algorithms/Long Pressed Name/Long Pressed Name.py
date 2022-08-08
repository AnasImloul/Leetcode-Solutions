class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        #dic for memoization
		dic = {}
        def dfs(i, j):
            if (i, j) in dic:
                return dic[(i, j)]
            
			#see if there is any case where both i and j reach to the end, cuz that will be the true condition
			#I only need one True 
            if i >= len(name):
                return j == len(typed)
			#we iterated through the end of typed, and not yet for name 
            if j >= len(typed):
                return False
            
			#if the characters don't match, return False
            if name[i] != typed[j]:
                dic[(i, j)] = False
                return False
            
			#if the two characters match
			#two options, either you move on (dfs(i + 1, j + 1)) or you consider it as an extra character (dfs(i, j + 1))
			#return if any of them is True, which means that i, j reach to the end as aforementioned
            dic[(i, j)] = dfs(i + 1, j + 1) or dfs(i, j + 1)
            return dic[(i, j)]
        
		#start from index 0, 0
        return dfs(0, 0)

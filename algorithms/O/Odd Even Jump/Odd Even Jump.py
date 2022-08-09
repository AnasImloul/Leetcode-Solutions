class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        
        l = len(arr)
        res = [False]*l
        res[-1] = True
        
        # for odd jump: for i, get next larger one 
        odd_next = [i for i in range(l)]
        stack = [] # mono inc for ind
        for n, i in sorted([(arr[i], i) for i in range(l)]):
            while stack and stack[-1]<i:
                odd_next[stack.pop()] = i
            stack.append(i)
                
        # for even jump: for i, get next smaller one 
        even_next = [i for i in range(l)]
        stack = [] # mono inc for ind
        for n, i in sorted([(-arr[i], i) for i in range(l)]):
            while stack and stack[-1]<i:
                even_next[stack.pop()] = i
            stack.append(i)
            
        # dp 
        @lru_cache(None)
        def dp(i, odd):
            if i == l-1:
                return True
            ind = odd_next[i] if odd else even_next[i]
            
            if ind == i:
                return False
            
            return dp(ind, not odd)
        
        for i in range(l-1):
            res[i] = dp(i, True)
        return sum(res)

class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr)
        ans = -1
        if n == m: return m #just in case
        
#       make in "inverted" array with artificial ends higher then everything between

        sor= [0 for _ in range(n+2)]
        for i in range(n):
            sor[(arr[i])] = i+1 
        sor[0] = sor[n+1] = n+1
        
#       scan and see, if ones in the middle of space of length m appear 
#       before ones on its ends,
#       and find the latest of such spaces to disappear, if exists

        for i in range(1, n-m+2): 
            if all(sor[i-1]>sor[j] and sor[i+m]>sor[j] for j in range(i,i+m)):
                if min(sor[i-1]-1,sor[i+m]-1)>ans: ans = min(sor[i-1]-1,sor[i+m]-1) 
        return ans

class Solution:
    def merge(self, A: List[List[int]]) -> List[List[int]]:
	#sort array wrt its 0'th index
        A.sort(key=lambda x:x[0])
        i=0
        while i<(len(A)-1):
            if A[i][1]>=A[i+1][0]:
                A[i][1]=max(A[i+1][1],A[i][1])
                A.pop(i+1)
            else:
                i+=1
        return(A)
                

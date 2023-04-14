class Solution:
    def splitArraySameAverage(self, A: List[int]) -> bool:
        A.sort()
        DP=[set() for _ in range(len(A)//2+1)]    #DP[i] stores the all available sum with i items in a bracket
        all_sum=sum(A)
        DP[0]=set([0])
        for item in A:                  #iterate over items in the list
            for count in range(len(DP)-2,-1,-1):          # iterate backwards w.r.t. the bracket size
                if len(DP[count])>0:                             # if DP[i] is not empty, then update DP[i+1] by adding the current item into all sums in DP[i]
                    for a in DP[count]:
                        DP[count+1].add(a+item)
        for size in range(1,len(DP)):
            if all_sum*size/len(A) in DP[size]:
                return True
        return False
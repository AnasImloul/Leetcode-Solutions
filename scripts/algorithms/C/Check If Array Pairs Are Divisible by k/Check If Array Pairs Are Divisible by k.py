# Runtime: 669 ms (Top 98.26%) | Memory: 27.7 MB (Top 90.32%)
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        count = [0]*k
        for num in arr:
            count[num%k] +=1 #will keep count of the following values, i.e 0== multiple of K, 1== multiple for k + 1, 2 == multiple of k + 2,3 == multiple of k + 3 ,4 multiple of k + 4.
        i,j =1,k-1
        pairs = 0
        while i<j :
            if count[i]!=count[j]:
                return False
            pairs += count[i] #count number of pairs!
            i+=1
            j-=1
        if pairs>0 and i==j: #I didn't get this condition yet!
            pairs+=count[i]/2
        pairs+= count[0]/2
        n = len(arr)
        return pairs == n//2
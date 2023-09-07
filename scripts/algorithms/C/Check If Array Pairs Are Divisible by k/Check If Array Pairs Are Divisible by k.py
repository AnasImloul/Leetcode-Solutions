# Runtime: 556 ms (Top 81.4%) | Memory: 30.00 MB (Top 97.8%)

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        #The idea is to count the residues
        
        #If every residue has the counter residue
        #such that x+y == k,then we found a pair
        
        count = [0]*k
        for num in arr:
            count[num%k] +=1
        
        #Now since we have 0,1,2,.....k-1 as residues
        #If count[1] == count[k-1],pairs+=count[1]
        #since we have odd number of complimenting residues,
        #we should also care about residue=0 and residue=k//2
        
        i,j =1,k-1
        pairs  = 0
        while i<j :
            if count[i]!=count[j]:
                return False
            pairs += count[i]
            i+=1
            j-=1
        if pairs>0 and i==j:
            pairs+=count[i]/2
        pairs+= count[0]/2
        n = len(arr)
        return pairs == n//2
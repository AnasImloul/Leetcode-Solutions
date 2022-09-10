# Runtime: 8217 ms (Top 5.03%) | Memory: 52.2 MB (Top 99.70%)
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:

        i=0
        while True:
            if i==len(triplets):
                break
            for j in range(3):
                if triplets[i][j]>target[j]:
                    triplets.pop(i)
                    i-=1
                    break
            i+=1

        a = [x[0] for x in triplets]
        b = [x[1] for x in triplets]
        c = [x[2] for x in triplets]

        if target[0] not in a:
            return False
        if target[1] not in b:
            return False
        if target[2] not in c:
            return False
        return True
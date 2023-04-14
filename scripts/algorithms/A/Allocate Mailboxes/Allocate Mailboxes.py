from statistics import median

class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()

        # cost to serve specific houses with one mailbox
        def cost_one_box(houses):
            box = int(median(houses))
            return sum(abs(house - box) for house in houses)

        # C[i][j] = cost of serving houses 0...i with mailboxes 0...j
        C = [[0 for _ in range(k)] for _ in range(len(houses))]
        for j in range(k):
            C[0][j] = 0
        for i in range(len(houses)):
            C[i][0] = cost_one_box(houses[:i+1])
        
        # C[i][j] = min([C[i'][j-1] + cost of serving houses i'+1...i with mailbox j] for i' in [0 (or j-1)...i-1]) 
        for i in range(1, len(houses)):
            for j in range(1, k):
                C[i][j] = min(C[_i][j-1] + cost_one_box(houses[_i+1:i+1]) for _i in range(min(i-1,j-1), i))
                
        return C[-1][-1]
                

         
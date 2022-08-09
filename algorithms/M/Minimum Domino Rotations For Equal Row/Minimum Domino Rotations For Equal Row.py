class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        sames = [tops[i] for i in range(len(tops)) if tops[i] == bottoms[i]]
		
        same_count = collections.Counter(sames)
        bottom_count = collections.Counter(bottoms)
        top_count = collections.Counter(tops)
        
        for n in range(1,7):
            if bottom_count[n] + top_count[n] - same_count[n] == len(tops):
                return min(bottom_count[n], top_count[n]) - same_count[n]
            
        return -1

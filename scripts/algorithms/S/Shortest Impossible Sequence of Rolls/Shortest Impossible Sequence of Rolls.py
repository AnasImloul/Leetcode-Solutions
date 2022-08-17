class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        ans = 1
        data = set()
        
        for roll in rolls:
            data.add(roll)
            
            if len(data) == k:
                ans += 1
                data.clear()
        
        return ans

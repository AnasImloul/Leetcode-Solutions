class Solution:
    def countOdds(self, low: int, high: int) -> int:        
        total_nums = high - low
        
        answer = total_nums // 2
        
        if low % 2 == 1 and high % 2 == 1:
            return answer + 1
        
        if low % 2 == 1:
            answer = answer + 1
            
        if high % 2 == 1:
            answer = answer + 1
        
        return answer

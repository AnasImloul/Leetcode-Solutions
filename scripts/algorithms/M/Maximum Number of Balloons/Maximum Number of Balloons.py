class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = {'b': 0, 'a': 0, 'l': 0, 'o': 0, 'n': 0}
        
        for char in text:
            if not char in freq:
                continue
                
            step = 0.5 if char == 'l' or char == 'o' else 1
            
            freq[char] += step
        
        result = min(freq.values())
        
        return floor(result)
class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        vals = {'c': 0, 'r': 1, 'o': 2, 'a': 3, 'k': 4}
        croaks = [0] * 4
        frogs = 0

        for c in croakOfFrogs:
            val = vals[c]
            if val:
                if not croaks[val - 1]:
                    return -1
                croaks[val - 1] -= 1
                
            if val != 4:
                croaks[val] += 1
            
            frogs = max(frogs, sum(croaks))
        
        return frogs if not sum(croaks) else -1
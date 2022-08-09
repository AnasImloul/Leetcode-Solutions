class Solution:
    def flipLights(self, n: int, presses: int) -> int:
        if not presses: 
            return 1
        elif n < 3:
            if n == 1: 
                return 2
            elif presses >= 2:
                return 4
            else:
                return 3
        else:
            if presses >= 3: 
                return 8
            elif presses == 2:
                return 7
            else:
                return 4

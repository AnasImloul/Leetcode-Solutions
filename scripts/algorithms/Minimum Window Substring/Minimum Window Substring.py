class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tcounter = defaultdict(int)
        for c in t:
            tcounter[c] += 1
        
        start = 0
        scounter = defaultdict(int)
        ml = ''
        win = False
        for i, c in enumerate(s):
            scounter[c] += 1
            
            if not win:
                win = True
                for k, v in tcounter.items():
                    if scounter[k] < v:
                        win = False
                        break
            
            if win:
                while scounter[s[start]] - 1 >= tcounter[s[start]]:
                    scounter[s[start]] -= 1
                    start += 1
                
                if not ml or i - start + 1 < len(ml):
                    ml = s[start:i+1]
                    
        return ml

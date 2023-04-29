class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        
        @cache
        def fn(lo, hi): 
            """Return possible answers of s[lo:hi]."""
            if lo+1 == hi: return {int(s[lo])}
            ans = set()
            for mid in range(lo+1, hi, 2): 
                for x in fn(lo, mid): 
                    for y in fn(mid+1, hi): 
                        if s[mid] == "+" and x + y <= 1000: ans.add(x + y)
                        elif s[mid] == "*" and x * y <= 1000: ans.add(x * y)
            return ans 
                
        target = eval(s)
        cand = fn(0, len(s))
        ans = 0 
        for x in answers: 
            if x == target: ans += 5
            elif x in cand: ans += 2
        return ans 
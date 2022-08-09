'''
w: BFS
h: for each possible number (node), we have two possible operations (add, rotate)
    it seems to be a 2^100 possible number, however, note:
    1) add a to number of odd index, we will get to the same number after 10 rounds of add
    2) s has even length, if b is odd, we can get the same number after n round
    3) for each shift, we would get different number at even index in 10 rounds
    
    so we would have 10 * n * 10 number at most, then we can use BFS + memo
'''
import collections

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        seen = set()
        deque = collections.deque([s])

        while deque:
            #print(deque)
            curr = deque.popleft()
            seen.add(curr)
            
            #1.add
            ad = self.add_(curr, a)
            if ad not in seen:
                deque.append(ad)
                seen.add(ad)

            
            #2. rotate:
            ro = self.rotate_(curr, b)
            if ro not in seen:
                deque.append(ro)
                seen.add(ro)

        return min(seen)
        
        
    def add_(self,s,a):
        res = ''
        for idx, i in enumerate(s):
            if idx % 2 == 1:
                num = (int(i) + a) % 10
                res += str(num)
            else:
                res += i
                
        return res
    
    
    def rotate_(self, s, b):
        idx = len(s)-b
        res = s[idx:] + s[0:idx]
        return res

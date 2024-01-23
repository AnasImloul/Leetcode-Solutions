// Runtime: 44 ms (Top 92.53%) | Memory: 16.90 MB (Top 59.64%)

from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        radiant = deque()
        dire = deque()
        for i, s in enumerate(senate):
            if s == 'R':
                radiant.append(i)
            else:
                dire.append(i)
        while radiant and dire:
            r_idx = radiant.popleft()
            d_idx = dire.popleft()
            if r_idx < d_idx:
                radiant.append(r_idx + n)
            else:
                dire.append(d_idx + n)
        return "Radiant" if radiant else "Dire"


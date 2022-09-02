# Runtime: 2036 ms (Top 22.82%) | Memory: 203 MB (Top 6.04%)
from collections import defaultdict
from functools import lru_cache

class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        N = len(req_skills)
        skills = {skill: i for i, skill in enumerate(req_skills)}
        people_mask = defaultdict(int)
        for i, cur_skills in enumerate(people):
            mask = 0
            for skill in cur_skills:
                mask |= 1<<skills[skill]
            people_mask[i] = mask
        self.path = []
        self.res = float('inf')
        self.respath = None
        @lru_cache(None)
        #i: people i
        #l: length of current self.path
        #mask: mask for current skills
        def dfs(i, l, mask):
            if mask == (1<<N) - 1:
                if l < self.res:
                    self.res = l
                    self.respath = self.path[:]
                return
            if i == len(people): return
            if l >= self.res:
                return
            dfs(i+1, l, mask)
            self.path.append(i)
            if mask & people_mask[i] != people_mask[i]: dfs(i+1, l+1, mask | people_mask[i])
            self.path.pop()
        dfs(0,0,0)
        return self.respath
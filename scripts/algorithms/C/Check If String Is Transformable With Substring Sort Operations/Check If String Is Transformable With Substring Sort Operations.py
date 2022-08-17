from collections import defaultdict
class Solution:
    def isTransformable(self, s: str, t: str) -> bool:
        index = defaultdict(list)
        for i, c in enumerate(s):
            index[c].append(i)
        curpos = defaultdict(int)
        for c in t:
            if curpos[c] == len(index[c]): return False
            for i in range(int(c)):
                i = str(i)
                if curpos[i] < len(index[i]) and index[i][curpos[i]] < index[c][curpos[c]]:
                    return False
            curpos[c] += 1
        return True
from collections import defaultdict
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        hashmap = defaultdict(set)
        for x, y in points:
            hashmap[x].add(y)
            
        min_area = math.inf
             
        i = 0
        for x1, y1 in points:
            i += 1
            for x2, y2 in points[i:]:
                if x1 != x2 and y1 != y2:
                    if y2 in hashmap[x1] and y1 in hashmap[x2]:
                        min_area = min(min_area, abs(x1 - x2) * abs(y1 - y2))
                        if min_area == 1:
                            return 1
                
        return min_area if min_area != math.inf else 0

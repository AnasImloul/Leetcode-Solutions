class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        d = collections.defaultdict(list)
        
        for i,(start, end, height) in enumerate(buildings):
            d[start].append(height)
            d[end].append(-height)
            
        l = list(d.keys())
        l.sort()
        
        result = []
        
        active = []
        
        for key in l:
            o = d[key]
            o.sort(reverse=True)
            for j in o:
                if j > 0:
                    if not result or not active:
                        result.append([key, j])
                        active.append(j)
                    else:
                        if j > active[-1]:
                            result.append([key, j])
                            active.append(j)
                        else:
                            active.insert(bisect_left(active, j), j)
                else:
                    idx = active.index(-j)
                    if idx == len(active) - 1:
                        active.pop()
                        if active:
                            result.append([key, active[-1]])
                        else:
                            result.append([key, 0])
                    else:
                        active.pop(idx)
        
        return result
                        

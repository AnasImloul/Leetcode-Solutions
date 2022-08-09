import collections

class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:

        n = len(graph)
        ans = []
        
        for i in range(n):
            if not graph[i]:
                ans.append(i)
        
        def loop(key, loops):
    
            loops.append(key)
            for i in graph[key]:
                if i in loops:
                    return False
                elif i in ans: 
                    continue
                else:
                    r = loop(i, loops)
                    if r == True: 
                        continue
                    else: 
                        return False

            idx = loops.index(key)
            loops.pop(idx)
            return True
                    
        for i in range(n):
            loops = []
            if i in ans:
                continue
            r = loop(i, loops)
            if r == True: ans.append(i)
 
        return sorted(ans)

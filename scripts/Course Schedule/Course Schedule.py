class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
                 
        pre = {} # course: list of prerequisites
        dep = {} # course: list of dependents
        for p in prerequisites:
            if p[0] not in pre:
                pre[p[0]] = set()
            if p[1] not in dep:
                dep[p[1]] = set()
            pre[p[0]].add(p[1])
            dep[p[1]].add(p[0])

        # Kahn's algorithm
        l = []
        s = set()
        for i in range(numCourses):
            if i not in dep: # if no dependents (incoming edge)
                s.add(i) 
        while s:
            n = s.pop()
            l.append(n)
            if n in pre: # if n has prerequisites
                for m in pre[n]: # for each prerequisites m
                    dep[m].remove(n) # remove n from m's dependents list
                    if not dep[m]: # if m has no more dependents
                        s.add(m)
                        
        return len(l) == numCourses
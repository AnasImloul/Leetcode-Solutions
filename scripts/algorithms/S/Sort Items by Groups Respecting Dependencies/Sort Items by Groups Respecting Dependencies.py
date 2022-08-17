class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        before = {i:set() for i in range(n)}
        after = {i:set() for i in range(n)}
        beforeG = {i:set() for i in range(m)}
        afterG = {i:set() for i in range(m)}
        groups = {i:set() for i in range(m)}
        qg = collections.deque()
        lazy = collections.deque()
        for i in range(n):
            if group[i] != -1:
                groups[group[i]].add(i)
            for x in beforeItems[i]:
                before[i].add(x)
                after[x].add(i)
                if group[x] != group[i] and group[x] != -1 and group[i] != -1:
                    beforeG[group[i]].add(group[x])
                    afterG[group[x]].add(group[i])
        for i in range(n):
            if group[i] == -1 and not before[i]:
                lazy.append(i)

        for i in range(m):
            if not beforeG[i]:
                qg.append(i)
        ans = []
        while qg:
            while lazy:
                i = lazy.popleft()
                ans.append(i)
                for j in after[i]:
                    before[j].remove(i)
                    if not before[j] and group[j] == -1:
                        lazy.append(j)
            g = qg.popleft()
            q = collections.deque()
            for member in groups[g]:
                if not before[member]:
                    q.append(member)
            while q:
                i = q.popleft()
                ans.append(i)
                groups[g].remove(i)
                for j in after[i]:
                    before[j].remove(i)
                    if not before[j]:
                        if group[j] == g:
                            q.append(j)
                        if group[j] == -1:
                            lazy.append(j)     
            if groups[g]:
                return []
            for p in afterG[g]:
                beforeG[p].remove(g)
                if not beforeG[p]:
                    qg.append(p)
        while lazy:
            i = lazy.popleft()
            ans.append(i)
            for j in after[i]:
                before[j].remove(i)
                if not before[j] and group[j] == -1:
                    lazy.append(j)
        return ans if len(ans) == n else []
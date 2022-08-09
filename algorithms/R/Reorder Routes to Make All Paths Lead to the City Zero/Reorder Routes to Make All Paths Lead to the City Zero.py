from collections import defaultdict
class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        count, stack, visited = 0, [ 0 ], set() #Add root node to stack
        neighbours = defaultdict(list) #To store neighbours
		adjacency = defaultdict(list) #To store adjacency
        for i, j in connections:
            adjacency[i].append(j)
            neighbours[i].append(j)
            neighbours[j].append(i)
        while stack:
            current = stack.pop()
            if current in visited:
                continue
            else:
                visited.add(current)
            for i in neighbours[current]:
                if i in visited:
                    continue
                if current not in adjacency[i]:
                    count += 1
                stack.append(i)
        return count

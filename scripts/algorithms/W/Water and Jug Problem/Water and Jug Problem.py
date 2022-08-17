class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        n1, n2, t = jug1Capacity, jug2Capacity, targetCapacity
        if n1 == t or n2 == t or n1 + n2 == t:
            return True
        if n1 + n2 < t:
            return False
        if n1 < n2:
            n1, n2 = n2, n1
        stack = []
        visited = set()
        d = n1 - n2
        if d == t:
            return True
        while d > n2:
            d -= n2
            if d == t:
                return True
        stack.append(d)
        while stack:
            #print(stack)
            d = stack.pop()
            visited.add(d)
            n = n1 + d
            if n == t:
                return True
            n = n1 - d
            if n == t:
                return True
            while n > n2:
                n -= n2
                if n == t:
                    return True
            if n < n2 and n not in visited:
                stack.append(n)
            n = n2 - d
            if n == t:
                return True
            if n not in visited:
                stack.append(n)
        return False

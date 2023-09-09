# Runtime: 4131 ms (Top 24.3%) | Memory: 185.60 MB (Top 35.5%)

class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        ans = 0
        seen = {start}
        queue = deque([start])
        while queue: 
            for _ in range(len(queue)): 
                val = queue.popleft()
                if val == goal: return ans 
                if 0 <= val <= 1000: 
                    for x in nums: 
                        for op in (add, sub, xor): 
                            if op(val, x) not in seen: 
                                seen.add(op(val, x))
                                queue.append(op(val, x))
            ans += 1
        return -1 
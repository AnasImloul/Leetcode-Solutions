class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        self.ans = None
        def dfs(path, used, i):
            self.steps += 1
            if i == len(path):
                self.ans = path[:]
                return True
            if path[i] != 0:
                return dfs(path, used, i + 1)
            my_ans = [0]
            for x in range(n, 0, -1):
                if x in used:
                    continue
                if x == 1:
                    path[i] = x
                    used.add(1)
                    
                    if dfs(path, used, i + 1):
                        return True
                    
                    path[i] = 0
                    used.remove(1)
                if i + x < len(path) and path[i + x] == 0:
                    path[i + x] = path[i] = x
                    used.add(x)
                    
                    if dfs(path, used, i + 1):
                        return True
                    
                    path[i + x] = path[i] = 0
                    used.remove(x)

            return False

        dfs([0] * (1 + 2 * (n - 1)), set(), 0)
        
        return self.ans

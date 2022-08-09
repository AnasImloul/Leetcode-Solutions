class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        hash_map = {}
        for i in range(0 , len(rounds)-1):
            if i == 0:
                start = rounds[i]
            elif rounds[i] == n:
                start = 1
            else:
                start = rounds[i] + 1
            end = rounds[i+1]
            if start <= end:
                for i in range(start , end + 1):
                    if i in hash_map:
                        hash_map[i] += 1
                    else:
                        hash_map[i] = 1
            else:
                for i in range(start , n + 1):
                    if i in hash_map:
                        hash_map[i] += 1
                    else:
                        hash_map[i] = 1
                for i in range(1 , end + 1):
                    if i in hash_map:
                        hash_map[i] += 1
                    else:
                        hash_map[i] = 1
        k = list(hash_map.keys())
        v = list(hash_map.values())
        ans = []
        m = -1
        i = 0
        j = 0
        while i < len(k) and j < len(v):
            if len(ans) == 0:
                ans.append(k[i])
                m = v[j]
            elif m < v[j]:
                ans = []
                ans.append(k[i])
                m = v[j]
            elif m == v[j]:
                ans.append(k[i])
            i += 1
            j += 1
        ans = sorted(ans)
        return ans


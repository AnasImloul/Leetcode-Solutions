class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        hash_map = {s[0]: 1}
        x = hash_map
        prefix = [hash_map]
        for i in range(1, len(s)):
            x = x.copy()
            x[s[i]] = x.get(s[i], 0) + 1
            prefix.append(x)
            
        result = []
        for query in queries:
            cnt = 0
            for key, value in prefix[query[1]].items():
                if query[0] > 0:
                    x = value - prefix[query[0]-1].get(key, 0)
                else:
                    x = value
                if x % 2:
                    cnt+=1
            if cnt - 2 * query[2] > 1:
                result.append(False)
            else:
                result.append(True)
        return result

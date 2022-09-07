# Runtime: 4914 ms (Top 7.28%) | Memory: 66.6 MB (Top 91.64%)
class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:

        properties.sort(key=lambda x: (-x[0],x[1]))

        ans = 0
        curr_max = 0

        for _, d in properties:
            if d < curr_max:
                ans += 1
            else:
                curr_max = d
        return ans
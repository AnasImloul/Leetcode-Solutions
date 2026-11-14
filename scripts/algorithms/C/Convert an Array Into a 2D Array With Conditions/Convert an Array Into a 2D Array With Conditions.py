# Runtime: 3 ms (Top 60.49%) | Memory: 19.00 MB (Top 93.09%)

class Solution:
    def findMatrix(self, v: List[int]) -> List[List[int]]:
        um = {}
        for i in v:
            um[i] = um.get(i, 0) + 1

        ans = []
        while um:
            temp = []
            to_erase = []
            for f, s in um.items():
                temp.append(f)
                s -= 1
                if s == 0:
                    to_erase.append(f)
                um[f] = s
            ans.append(temp)
            for i in to_erase:
                del um[i]
        return ans

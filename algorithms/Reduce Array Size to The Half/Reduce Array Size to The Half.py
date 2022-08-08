class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        n = len(arr)
        half = n // 2
        
        c = Counter(arr)
        s = 0
        ans = 0
        
        for num, occurances in c.most_common():
            s += occurances
            ans += 1
            if s >= half:
                return ans
        return ans

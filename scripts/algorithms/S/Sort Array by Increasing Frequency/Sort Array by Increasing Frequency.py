class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        
        r = Counter(nums).most_common()
        r.sort(key = lambda x: x[0], reverse=True)
        r.sort(key = lambda x: x[1])
        
        t = []
        for i in r:
            a, b = i
            t.extend([a]*b)
            
        return t

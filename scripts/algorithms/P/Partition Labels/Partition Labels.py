class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        m = map(s.index, s) # s: 'ababc' -> m: [0, 1, 0, 1, 4]
        n = len(s)
        res = []
        
        start = 0
        i = 0
        while i < n:
            for j in range(i+1, n):
                if m[j] <= i:
                    i = j
            i += 1
            res.append(i - start)
            start = i
            
        return res
class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        d = defaultdict(set)
        for row,seat in reservedSeats:
            d[row].add(seat)
        
        def row(i):
            a1 = not set((2,3,4,5)).intersection(d[i])
            a2 = not set((6,7,8,9)).intersection(d[i])
            if  a1 and a2:
                return 2
            if  a1 or a2:
                return 1
            return 1 if not set((4,5,6,7)).intersection(d[i]) else 0
        
        return sum((row(i) for i in d.keys())) + (n-len(d)) * 2


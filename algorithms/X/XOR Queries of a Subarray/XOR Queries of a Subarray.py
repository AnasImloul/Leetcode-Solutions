class Solution(object):
    def xorQueries(self, arr, queries):
        """
        :type arr: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        xors=[0]*len(arr)
        for i in range(len(arr)): xors[i]=xors[i-1]^arr[i] if i>0 else arr[0]
        return [xors[r]^xors[l-1] if l>0 else xors[r] for l,r in queries]

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        hm = {}
        # adding entries in hashmap to check frequency
        for i, v in enumerate(nums):
            if v not in hm:
                hm[v] = 1
            else:
                hm[v] += 1
        # checking frequency of item and adding output to an array
        for key, value in hm.items():
            if value > 1:
                res.append(key)
        return res
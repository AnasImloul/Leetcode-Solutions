class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        hashmap = {}
        for i in nums:
            if i in hashmap.keys():
                hashmap[i] += 1
            else:
                hashmap[i] = 1
        sum = 0
        for k, v in hashmap.items():
            if v == 1: sum += k
        return sum

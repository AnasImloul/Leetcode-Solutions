# Runtime: 3233 ms (Top 5.15%) | Memory: 31.6 MB (Top 46.98%)
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        odd, even = defaultdict(int), defaultdict(int)
        for i in range(n):
            if i % 2 == 0:
                even[nums[i]] += 1
            else:
                odd[nums[i]] += 1
        topEven, secondEven = (None, 0), (None, 0)
        for num in even:
            if even[num] > topEven[1]:
                topEven, secondEven = (num, even[num]), topEven
            elif even[num] > secondEven[1]:
                secondEven = (num, even[num])
        topOdd, secondOdd = (None, 0), (None, 0)
        for num in odd:
            if odd[num] > topOdd[1]:
                topOdd, secondOdd = (num, odd[num]), topOdd
            elif odd[num] > secondOdd[1]:
                secondOdd = (num, odd[num])
        if topOdd[0] != topEven[0]:
            return n - topOdd[1] - topEven[1]
        else:
            return n - max(secondOdd[1] + topEven[1], secondEven[1] + topOdd[1])
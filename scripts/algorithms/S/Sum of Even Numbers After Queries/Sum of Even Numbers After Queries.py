# Runtime: 1565 ms (Top 5.26%) | Memory: 20.6 MB (Top 46.36%)
class Solution:
# O(n) || O(1)
# Runtime: 583ms 72.40% || memory: 20.5mb 37.69%
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        totalEvenNumSum = sum([num for num in nums if num % 2 == 0])
        result = []

        for val, idx in queries:
            oldVal = nums[idx]
            nums[idx] += val

            if oldVal % 2 == 0:
                totalEvenNumSum -= oldVal

            if nums[idx] % 2 == 0:
                totalEvenNumSum += nums[idx]

            result.append(totalEvenNumSum)

        return result

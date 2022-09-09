# Runtime: 793 ms (Top 10.96%) | Memory: 22.9 MB (Top 23.08%)
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        return [k for k,v in Counter(nums).items() if v>=2][::-1]
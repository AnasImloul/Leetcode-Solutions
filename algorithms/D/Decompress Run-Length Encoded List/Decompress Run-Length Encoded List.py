class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        answer = []
        
        for i in range(0, len(nums), 2):
            for j in range(0, nums[i]):
                answer.append(nums[i + 1])
        
        return answer

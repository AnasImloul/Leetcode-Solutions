class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        even_count = 0
        for elem in nums:
            if(len(str(elem))%2 == 0):
                even_count += 1
        return even_count
        

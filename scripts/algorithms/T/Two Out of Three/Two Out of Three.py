# Runtime: 65 ms (Top 93.8%) | Memory: 16.30 MB (Top 83.7%)

class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        output = []
        for i in nums1:
            if i in nums2 or i in nums3:
                if i not in output:
                    output.append(i)
        for j in nums2:
            if j in nums3 or j in nums1:
                if j not in output:
                    output.append(j)
        return output
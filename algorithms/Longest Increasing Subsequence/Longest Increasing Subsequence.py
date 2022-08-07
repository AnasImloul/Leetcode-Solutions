from bisect import bisect_left


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        temp = []
        tmp_size = -1
        for ele in nums:
            idx = bisect_left(temp, ele)
            if idx > tmp_size:
                temp.append(ele)
                tmp_size += 1
            else:
                temp[idx] = ele
        return tmp_size + 1
        

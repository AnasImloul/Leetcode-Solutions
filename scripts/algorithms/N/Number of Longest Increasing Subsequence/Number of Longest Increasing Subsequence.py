class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        
        if not nums or len(nums) == 0:
            return 0
        
        def find_pos(sub, val):
            left, right = 0, len(sub) - 1
            while left < right:
                mid = (left + right) >> 1
                if sub[mid] >= val: 
                    right = mid
                else:
                    left = mid + 1
            return left 
        
    
        sub_list = []
        
        for val in nums:
            if len(sub_list) == 0 or val > sub_list[-1][-1][0]:
                # should append a new element at the end
                cur_count = sum([x[1] for x in sub_list[-1] if val > x[0]]) if len(sub_list) != 0 else 1
                sub_list.append([(val, cur_count)])
            else:
                # get the last number to turn it back to a LIS problem
                cur_sub = [array[-1][0] for array in sub_list]
                pos = find_pos(cur_sub, val)
                # if pos == 0, means it is smallest, no need to look the previous level and set it to be 1
                cur_count = sum([x[1] for x in sub_list[pos - 1] if val > x[0]]) if pos > 0 else 1
                sub_list[pos].append((val, cur_count))
      
        return sum([x[1] for x in sub_list[-1]])
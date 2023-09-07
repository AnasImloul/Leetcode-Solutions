# Runtime: 2155 ms (Top 31.7%) | Memory: 55.78 MB (Top 94.8%)

class Solution:
    def colorTheArray(self, n, queries):
        ans, nums, count = [], [0]*n, 0

        for i in range(len(queries)):
            index, color = queries[i][0], queries[i][1]

            if index-1 >= 0 and nums[index] != 0 and nums[index-1] == nums[index]:
                count -= 1
            if index+1 < n and nums[index] != 0 and nums[index+1] == nums[index]:
                count -= 1

            nums[index] = color

            if index-1 >= 0 and nums[index] != 0 and nums[index-1] == nums[index]:
                count += 1
            if index+1 < n and nums[index] != 0 and nums[index+1] == nums[index]:
                count += 1

            ans.append(count)

        return ans

            





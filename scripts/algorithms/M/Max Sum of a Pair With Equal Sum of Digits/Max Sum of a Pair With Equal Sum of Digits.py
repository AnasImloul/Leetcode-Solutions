class Solution:     # The plan here is to:
                    # 
                    #   • sort the elements of nums into a dict of maxheaps,
                    #     according to sum-of-digits.
                    #
                    #   • For each key, determine whether there are at least two 
                    #     elements in that key's values, and if so, compute the
                    #     product of the greatest two elements.
                    #
                    #   • return the the greatest such product as the answer.

                    # For example:
					
                    #     nums = [6,15,13,12,24,21] –> {3:[12,21], 4:[13], 6:[6,15,24]}
					
                    #     Only two keys qualify, 3 and 6, for which the greatest two elements
                    #     are 12,21 and 15,24, respectively. 12+21 = 33 and 15+24 = 39,
                    #     so the answer is 39.

    def maximumSum(self, nums: List[int]) -> int:
        d, mx = defaultdict(list), -1
        digits = lambda x: sum(map(int, list(str(x))))      # <-- sum-of-digits function
       
        for n in nums:                                      # <-- construct max-heaps
            heappush(d[digits(n)],-n)                       #     (note "-n") 

        for i in d:                                         # <-- pop the two greatest values off
            if len(d[i]) > 1:                               #     each maxheap (when possible) and
                mx= max(mx, -heappop(d[i])-heappop(d[i]))   #     compare with current max value.
                                                           
        return mx
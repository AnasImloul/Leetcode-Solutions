class Solution:
    def minimumDeletions(self, s: str) -> int:
        # track the minimum number of deletions to make the current string balanced ending with 'a', 'b'
        end_a, end_b = 0,0 
        for val in s:
            if val == 'a':
                # to end with 'a', nothing to do with previous ending with 'a'
                # to end with 'b', need to delete the current 'a' from previous ending with 'b'
                end_b += 1
            else:
                # to end with 'a', need to delete the current 'b' from previous ending with 'a'
                # to end with 'b', nothing to do, so just pick smaller of end_a, end_b
                end_a, end_b = end_a+1, min(end_a, end_b)
        return min(end_a, end_b)


# helper data structure Scout
class Scout:
    
    def __init__(self, prev_idx=-1, count_of_equal=0):
        
        # record of index of last identical element
        self.prev_idx = prev_idx
        
        # count of identical elements so far
        self.count_of_equal = count_of_equal
    
    def __iter__(self):
		# ouput previous index, and count of equal in order
        return iter( (self.prev_idx, self.count_of_equal) )
    
    
        
class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        
        size = len(arr)
        
        pre_scout = defaultdict( Scout )
        pre_dist_sum = [0 for _ in range(size)]
        
        post_scout = defaultdict( Scout )
        post_dist_sum = [0 for _ in range(size)]
        
        
        ## Step_1:
        # update for pre_dist_sum table, direction is from left to right
        for i, element in enumerate(arr):
            
            prev_equal_idx, prev_count_of_equal = pre_scout[element]
            
            # update pre_dist_sum table if we have identical elements before index i
            if prev_count_of_equal:
                pre_dist_sum[i] += pre_dist_sum[ prev_equal_idx ] + (i - prev_equal_idx) * prev_count_of_equal
            
            # update Scout information for current element
            pre_scout[element] = i, prev_count_of_equal+1
            
        # --------------------------------------------------------------
        
        ## Step_2:
        # update for pos_dist_sum table, direction is from right to left
        for i, element in reversed( [*enumerate(arr)] ):
            
            post_equal_idx, post_count_of_equal = post_scout[element]

            # update post_dist_sum table if we have identical elements after index i
            if post_count_of_equal:
                post_dist_sum[i] += post_dist_sum[ post_equal_idx ] + (post_equal_idx - i) * post_count_of_equal
            
            # update Scout information for current element
            post_scout[element] = i, post_count_of_equal+1
            
            
        ## Step_3:
        # Generate final output by definition
        return [ pre_dist_sum[i] + post_dist_sum[i] for i in range(size) ]
        
        

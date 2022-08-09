class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        """
        
        
        q. is there a greedy wat to know tht shall i switch or not?
        a. 
            [1, 3, 6] [1, 4, 4]
            
            at i=1, we cannot greedily determine about switching.. we need lookahead, i.e DP
			
			at each (i) we have a choice
            if its currently not increasing:
                we have to see if switching will make it increasing
            else:
                we can move to i+1 since its already incr
                OR
                if switch is possible, we switch and cont.
        
        possible complexity:
            dp(i, prev1, prev2) :
        """
        
        @cache
        def dp(i, preva, prevb):
            
            if i == len(nums1):
                return 0
            
            if nums1[i] > preva and nums2[i] > prevb: 
                # we are increasing as is, we have 2 choices now, make swap if possible else dont
                if nums1[i] > prevb and nums2[i] > preva: 
                    # switch is also possible
                    return min(
                        1 + dp(i+1, nums2[i], nums1[i]),
                        dp(i+1, nums1[i], nums2[i])
                    )
                else:
                    return dp(i+1, nums1[i], nums2[i])
            else:
                # we only have 1 choice
                if nums1[i] > prevb and nums2[i] > preva:
                    # switch is possible
                    return 1 + dp(i+1, nums2[i], nums1[i]) # swithced
                else:
                    return inf
            
        return min(dp(1, nums1[0], nums2[0]), 1+dp(1, nums2[0], nums1[0]))

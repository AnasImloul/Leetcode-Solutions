# Runtime: 133 ms (Top 63.3%) | Memory: 16.65 MB (Top 94.0%)

class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        
        # previous continuous occurrence, current continuous occurrence
        pre_cont_occ, cur_cont_occ = 0, 1
        
        # counter for binary substrings with equal 0s and 1s
        counter = 0
        
		# scan each character pair in s
        for idx in range(1, len(s)):
            
            if s[idx] == s[idx-1]:
                
                # update current continuous occurrence
                cur_cont_occ += 1
            
            else:
                # update counter of binary substrings between prevous character group and current character group
                counter += min(pre_cont_occ, cur_cont_occ)

                # update previous as current's continuous occurrence
                pre_cont_occ = cur_cont_occ
                
                # reset current continuous occurrence to 1
                cur_cont_occ = 1
        
        # update for last time
        counter += min(pre_cont_occ, cur_cont_occ)
        
        return counter
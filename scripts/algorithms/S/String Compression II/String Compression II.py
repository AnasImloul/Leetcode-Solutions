class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        # Find min lenth of the code starting from group ind, if there are res_k characters to delete and 
		#       group ind needs to be increased by carry_over additional characters
        def FindMinLen(ind, res_k, carry_over=0): 
            
            # If we already found the min length - just retrieve it (-1 means we did not calculate it)
            if carry_over == 0 and dynamic[ind][res_k] != -1:
                return dynamic[ind][res_k]
            
            # Number of character occurences that we need to code. Includes carry-over.
            cur_count = carry_over + frequency[ind]

            # Min code length if the group ind stays intact. The code accounts for single-character "s0" vs. "s"  situation.
            min_len = 1 + min(len(str(cur_count)), cur_count - 1) + FindMinLen(ind+1,res_k)

            # Min length if we keep only 0, 1, 9, or 99 characters in the group - delete the rest, if feasible
            for leave_count, code_count in [(0,0), (1, 1), (9, 2), (99, 3)]:
                if cur_count > leave_count and res_k >= cur_count - leave_count:
                    min_len = min(min_len, code_count + FindMinLen(ind + 1,res_k - (cur_count - leave_count)))

            # If we drop characters between this character group and next group, like drop "a" in "bbbabb"
            next_ind = chars.find(chars[ind], ind + 1)
            delete_count = sum(frequency[ind+1:next_ind])
            if next_ind > 0 and res_k >= delete_count:
                min_len = min(min_len, FindMinLen(next_ind, res_k - delete_count, carry_over = cur_count))

            # If there was no carry-over, store the result
            if carry_over == 0: dynamic[ind][res_k] = min_len
            return min_len
        
        # Two auxiliary lists - character groups (drop repeated) and number of characters in the group
        frequency, chars = [], ""
        for char in s:
            if len(frequency)==0 or char != chars[-1]:
                frequency.append(0)
                chars = chars + char
            frequency[-1] += 1
        
        # Table with the results. Number of character groups by number of available deletions.  
        dynamic = [[-1] * (k + 1) for i in range(len(frequency))] + [[0]*(k + 1)]
        
        return FindMinLen(0, k)

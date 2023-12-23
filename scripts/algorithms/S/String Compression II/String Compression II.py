// Runtime: 1997 ms (Top 68.37%) | Memory: 360.00 MB (Top 27.55%)

class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        # We define f(i, curr_run_ch, run_length, nb_dels_remain) to return 
        # the minimum, additional, number of characters it will cost to run-length 
        # compress the substring s[i..n-1].
        # `curr_run_ch` is the character we have in the current "run", or the same
        # contiguous block of characters. 
        # `run_length` is the length of the current "run", or the length of the
        # contiguous block of identical characters.
		#     e.g. if we just encoded "aaaaa", `curr_run_ch` is "a" and `run_length` = 5
        # `nb_dels_remain` is the number of delete operations we have available to us,
        # should we choose to use them
        memo = {}
        def f(i, curr_run_ch, run_length, nb_dels_remain):
            if i == len(s):
                return 0
            
            key = (i, curr_run_ch, run_length, nb_dels_remain)
            if key in memo:
                return memo[key]
            
            # At character i, we have two possible options, we could choose to either
            # delete this character or keep this character. Each choice we make will
            # incurr some additional run-length encoding length for s[i..n-1]. We return
            # the minimum of the two.
            
            # Delete s[i]
            del_ch_cost = float('inf')
            if nb_dels_remain > 0:
                # Deleting s[i] means the latest character we kept stays the same AND
                # the current run-length of characters stays the same as well
                del_ch_cost = f(i + 1, curr_run_ch, run_length, nb_dels_remain - 1)
            
            # Keep s[i]
            keep_ch_cost = 0
            if s[i] == curr_run_ch:
			    # The new character at s[i] we are about to encode is the same as the character in the
				# current "run", we could choose to include it into the current run of course.
                # Be careful that if we started with run-length of 1, 9, 99, 999 and etc, encoding another
                # character same as `curr_run_ch`  into the same "run" will require an extra digit.
                # e.g. 'a' => '2a' '9a' => '10a', '99a' => '100a'
                extra_digit_cost = 0
                if run_length == 1 or len(str(run_length + 1)) > len(str(run_length)):
                    extra_digit_cost = 1
                keep_ch_cost = extra_digit_cost + f(i + 1, curr_run_ch, run_length + 1, nb_dels_remain)
            else:
                # s[i] != curr_run_ch, we are going to need to run-length encode at least
                # one instance of s[i] which would cost 1, plus whatever the cost to encode
                # the rest. Of course that also means the current "run" will "reset" and start anew with
				# a single character s[i]
                keep_ch_cost = 1 + f(i + 1, s[i], 1, nb_dels_remain)
            
            memo[key] = min(keep_ch_cost, del_ch_cost)
            return memo[key]
        
        return f(0, '', 0, k)

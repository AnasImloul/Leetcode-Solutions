# Runtime: 137 ms (Top 87.7%) | Memory: 17.15 MB (Top 48.6%)

class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        c = r = o = a = k = max_frog_croak = present_frog_croak = 0
        # need to know, at particular point,
        # what are the max frog are croaking,

        for i, v in enumerate(croakOfFrogs):
            if v == 'c':
                c += 1
				# c gives a signal for a frog
                present_frog_croak += 1
            elif v == 'r':
                r += 1
            elif v == 'o':
                o += 1
            elif v == 'a':
                a += 1
            else:
                k += 1
				# frog stop croaking
                present_frog_croak -= 1

            max_frog_croak = max(max_frog_croak, present_frog_croak)
            # if any inoder occurs;
            if c < r or r < o or o < a or a < k:
                return -1

        # if all good, else -1
        if present_frog_croak == 0 and c == r and r == o and o == a and a == k:
            return max_frog_croak
        return -1

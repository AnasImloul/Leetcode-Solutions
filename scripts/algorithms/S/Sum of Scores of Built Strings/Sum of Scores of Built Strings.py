def calcZ(s):
    # Z-function is a list of which i-th member is the lenght of the longest prefix 
    # shared between s and s[-(n-i):]. (This has the effect of Z[0]=0, not matched
    # with the definition of this problem which requires Z[0]=n.)
    # Ex. Z("aaaaa")    = [0, 4, 3, 2, 1]
    #     Z("aaabaab") = [0, 2, 1, 0, 2, 1, 0]
    #     Z("abacaba") = [0, 0, 1, 0, 3, 0, 1]
    n = len(s)
    z = [0] * n
    left, right = 0, 0  # Used to estimate starting z[i] vals.
    for i in range(1, n):
        
        #### THESE SECTION IS NOT NECESSARY, BUT SAY WE DON'T WANT TO START EVERY MEMBER AT 0,
        #### WE CAN ESTIMATE THE STARTING POINT THUS
        # Let 'left' and 'right' be the left- and right-index of the found prefix that ends rightmost.
        # Since we are calculating Z from left to right, the right bound tends toward the right.
        # Ex. s = "aabxaabxcaabxaabxay"
        # Upon calculation of z[1], we get z[1] = 1 (right bound = 1, rightmost)
        # So we set: left  = 1          (current position) and
        #            right = 1+1-1     (current position+z[i]-1)  *** this time it does close to nothing for us.
        # Now, upon calculation of z[4], we get z[4] = 4 (right bound = 7, rightmost)
        # So we set: left  = 4 and right = 4+4-1
        #
        # The fact that z[4] = 4 means that s[left:right] == s[0:(right-left)].
        # So for the next few rounds, substrings we are considering are bound to repeat.
        # Basically, the next few round of z[i] are also bound to repeat with z[i-left] too.
        # The EXCEPTION to this repeating z pattern is when z[i-left] is too large, so we have to
        # acknowledge the fact that z[i] cannot be larger than the len of what's left in the
        # string after this point (right-i+1) as well.
        if (i <= right):    # i within repeating z bound
            z[i] = min(z[i-left], right-i+1)
        # else: do nothing, let z[i] start at 0
        ####
        ####
        
        while (z[i] < n-i and           # As per definition, max val of z[i] must not exceed (n-i).
              s[z[i]] == s[i + z[i]]):  # As long as similar character chain continues, common prefix persists.
            z[i] += 1
            
        ####
        ####
        # Reset left-right bounds if appropriate.
        if z[i] + i - 1 > right:    # if the right bound of current prefix (z[i]+i-1) exceeds current 'right'
            left, right = i, z[i] + i - 1
        ####
        ####
        
    return z
    

class Solution:
    def sumScores(self, s: str) -> int:
        return sum(calcZ(s)) + len(s)

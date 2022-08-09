class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1 == s2:
            return True
        if len(s1) != len(s2):
            return False
            
        # Check both strings have same count of letters
        count1 = collections.defaultdict(int)
        count2 = collections.defaultdict(int)
        for c1, c2 in zip(s1, s2):
            count1[c1] += 1
            count2[c2] += 1
        if count1 != count2: return False
        
        # Iterate through letters and check if it results in a partition of 
        # string 1 where the collection of letters are the same
        # on the left (non-swapped) or right (swapped) sides of string 2
        # Then we recursively check these partitioned strings to see if they are scrambled
        lcount1 = collections.defaultdict(int) # s1 count from left
        lcount2 = collections.defaultdict(int) # s2 count from left
        rcount2 = collections.defaultdict(int) # s2 count from right
        for i in xrange(len(s1) - 1):
            lcount1[s1[i]] += 1          
            lcount2[s2[i]] += 1
            rcount2[s2[len(s1) - 1 - i]] += 1
            if lcount1 == lcount2:  # Left sides of both strings have same letters
                if self.isScramble(s1[:i + 1], s2[:i + 1]) and \
                   self.isScramble(s1[i + 1:], s2[i + 1:]):
                    return True
            elif lcount1 == rcount2: # Left side of s1 has same letters as right side of s2
                if self.isScramble(s1[:i + 1], s2[-(i + 1):]) and \
                   self.isScramble(s1[i + 1:], s2[:-(i + 1)]):
                    return True
        return False

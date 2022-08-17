class Solution(object):
    def minMovesToMakePalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count, length_of_s = 0, len(s)
        if length_of_s <= 2:
            return count
        for i in reversed(range(length_of_s)):
            if s[i] != s[0]:
                continue
            if i == 0:
				# move to middle is a speical case which takes len(s)/2 moves then do recursive for remaining part
                count += len(s)/2 + self.minMovesToMakePalindrome(s[1:])  
            else:
			    # this move takes len(s)-1 - i (move from i to last index len(s)-1)and then do recursive for remaining part
                count += len(s)-1-i + self.minMovesToMakePalindrome(s[1:i]+s[i+1:])
            break
        return count

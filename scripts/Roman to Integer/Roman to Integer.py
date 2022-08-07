class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        conv_map = {'I':1,'V':5,'X':10, 'L':50,'C':100,'D':500,'M':1000}
        total = 0
        for i in range(0, len(s)-1):
            if conv_map[s[i]] >= conv_map[s[i+1]]:
                total += conv_map[s[i]]
            else:
                total -= conv_map[s[i]]
        total += conv_map[s[len(s)-1]]
        return total  
		```
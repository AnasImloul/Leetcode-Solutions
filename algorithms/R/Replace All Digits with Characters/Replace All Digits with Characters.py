class Solution(object):
    def replaceDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []
        
        for i in range(len(s)):
            if i % 2 == 0:
                res.append(s[i])
            if i % 2 == 1:
                res.append( chr(ord(s[i-1]) + int(s[i])) )
                
        return ''.join(res) 

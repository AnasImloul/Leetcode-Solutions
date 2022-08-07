class Solution(object):
    def reverseWords(self, s):
        tmp = s.split()
        tmp.reverse()
        return ' '.join(tmp)

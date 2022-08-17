class Solution:
    def reverseWords(self, s: str) -> str:
        s = s + ' '
        l = len(s)
        t = ''
        w = ''
        for i in range(l):
            if s[i]!=' ':
                t = s[i] + t  # t stores the word in reverse order
            else:
				# w stores the reversed word in the same order
                w = w + t + ' ' # could have used .join() function and not write .strip()
                t = "" # value of t is null so that it won't affect upcoming words
        return w.strip() # removes extra whitespace

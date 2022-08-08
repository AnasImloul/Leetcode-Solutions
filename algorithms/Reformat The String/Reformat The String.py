class Solution:
    def reformat(self, s: str) -> str:
        # Store the alphabets and the numerics from the string in a seperat arrays
        alpha = []
        num = []
        # Initiate a res variable to store the resultant string
        res = ''
        
        for i in s:
            if i.isalpha():
                alpha.append(i)
            else:
                num.append(i)
                
        # It's not possible to create a permutation if the absolute difference b/w len(alpha) and len(num) > 1.
        if abs(len(alpha)-len(num)) > 1: return ''
        
        # Use Zip to create list of tuples.
        # For ex:- if alpha = ['a','b'] and num = ['1', '2'] then,
        # zip(alpha, num) = [('a', '1'), ('b', '2')]
        for ch, n in zip(alpha, num):
            res += (ch+n)
            
        if len(alpha) > len(num):
            res += alpha[-1]
        if len(num) > len(alpha):
            res = num[-1] + res
            
        return res

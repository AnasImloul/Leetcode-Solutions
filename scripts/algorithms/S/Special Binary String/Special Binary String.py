class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        
        l = 0
        balance = 0
        sublist = []
        for r in range(len(s)):
            balance += 1 if s[r]=='1' else -1
            if balance==0:
                sublist.append("1" + self.makeLargestSpecial(s[l+1:r])+ "0")
                l = r+1
        
        sublist.sort(reverse=True)
        return ''.join(sublist)
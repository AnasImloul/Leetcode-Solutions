class Solution:
    def numberOfLines(self, w: List[int], s: str) -> List[int]:
        r=[0]*2
        px=0
        l=1
        for i in range(len(s)):
            px+=w[ord(s[i])-97]
            if px>100:
                l+=1
                px=w[ord(s[i])-97]
                
            print(ord(s[i]))
        r[0]=l
        r[1]=px
        return r
        
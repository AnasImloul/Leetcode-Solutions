class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        lst1=[0]*26
        lst2=[0]*26
        for i in word1:
            lst1[ord(i)-97]+=1
        for i in word2:
            lst2[ord(i)-97]+=1
        for i in range(26):
            if (lst1[i]>0 and lst2[i]==0) or (lst1[i]==0 and lst2[i]>0):
                return False
        lst1.sort()
        lst2.sort()
        if lst1[:]==lst2[:]:
            return True
        return False
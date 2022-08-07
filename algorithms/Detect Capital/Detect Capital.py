class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        l=len(word)
        if l==1:
            return True
        if word[0]==word[0].lower() and word[1]==word[1].upper():
            return False
            
        u=False
        if word[0]==word[0].upper():
            if word[1]==word[1].upper():
                u=True
                
        for i in word[2:]:
            if i==i.upper() and u==False:
                return False
            elif i==i.lower() and u==True:
                return False
        return True

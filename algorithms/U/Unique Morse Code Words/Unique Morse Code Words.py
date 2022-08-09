    class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse=[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        alpha='abcdefghijklmnopqrstuvwxyz'
        k={}
        for i in alpha:
            for j in morse:
                k[i]=j
                morse.remove(j)
                break
        l=[]
        for word in words:
            m=''
            for i in word:
                m+=k[i]
            l.append(m)
        p=set(l)
        return(len(p))``

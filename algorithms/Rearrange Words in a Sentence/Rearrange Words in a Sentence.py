class Solution:
    def arrangeWords(self, text: str) -> str:
        l=list(text.split(" "))
        l=sorted(l,key= lambda word: len(word))
        l=' '.join(l)
        return l.capitalize()

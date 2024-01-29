// Runtime: 166 ms (Top 89.12%) | Memory: 19.20 MB (Top 76.17%)

class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        capital={i.lower():i for i in wordlist[::-1]}
        vovel={''.join([j if j not in "aeiou" else '.' for j in i.lower()]):i for i in wordlist[::-1]}
        wordlist=set(wordlist)
        res=[]
        for i in queries:
            if i in wordlist:
                res.append(i)
            elif i.lower() in capital:
                res.append(capital[i.lower()])
            elif ''.join([j if j not in "aeiou" else '.' for j in i.lower()]) in vovel:
                res.append(vovel[''.join([j if j not in "aeiou" else '.' for j in i.lower()])])
            else:
                res.append("")
        return res

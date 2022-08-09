class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        n = len(wordlist)
        d = {}
        sd = {}
        vd = {}
        cd = {}
        for i in range(n):
            d[wordlist[i]] = i
            s = wordlist[i].lower()
            if s not in sd:sd[s] = i 
            m = len(wordlist[i])
            tmp = []
            emp = ""
            for j in range(m):
                if wordlist[i][j] in 'aeiouAEIOU': tmp.append(j)
                else:emp+=wordlist[i][j].lower()
            cd[i] = emp
            vd[i] = tmp
            
        ans = []
        for word in queries:
            word_lower = word.lower()
            if word in d: 
                ans.append(word)
                continue            
            elif word_lower in sd:
                ans.append(wordlist[sd[word_lower]])
                continue
            else:
                vow_word = []
                con_word = "" 
                m = len(word)
                for i in range(m):
                    if word[i] in 'aeiouAEIOU' : vow_word.append(i)
                    else: con_word += word[i].lower()
                if vow_word == []:
                    ans.append("")
                    continue
                    
                flag = False
                for i in range(n):
                    vow_tmp = vd[i]
                    con_tmp = cd[i]
                    if vow_tmp == vow_word and con_tmp == con_word:
                        ans.append(wordlist[i])
                        flag = True
                        break
                if flag == True:continue
                ans.append("")
        return ans

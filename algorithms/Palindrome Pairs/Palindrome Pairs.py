class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        m = {}
        for i, word in enumerate(words):
            m[word] = i
        
        result = set()
        for i, word in enumerate(words):
            n, rev_word = len(word), word[::-1]
            prefix, suffix = word, rev_word
            
            for j in range(n+1):
                if prefix == suffix:
                    key = rev_word[:j]
                    if key in m and m[key] != i:
                        result.add((m[key], i))
                
                if j == n:
                    break
                
                prefix = prefix[:-1]
                suffix = suffix[1:]
            
            # print('pre', i, result)
            
            prefix, suffix = '', ''
            for j in range(n+1):
                if prefix == suffix:
                    if prefix == suffix:
                        key = rev_word[j:]
                        if key in m and m[key] != i:
                            result.add((i, m[key]))
                
                if j == n:
                    break
                
                prefix = word[n-j-1] + prefix
                suffix = suffix + rev_word[j]
            
            # print('post', i, result)
        
        return list(result)

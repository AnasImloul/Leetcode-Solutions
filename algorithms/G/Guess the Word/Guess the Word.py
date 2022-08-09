class Solution:
    def findSecretWord(self, words: List[str], master: 'Master') -> None:        
        k = 1 # for tracing the number of loops
        matches = 0
        blacklists = [[] for i in range(6)]
        
        while matches != 6:
            n = len(words)
            r = random.randint(0, n - 1)
            matches = master.guess(words[r])
            key = words[r]
            # print(k, n, r, matches, key)
            
            words.pop(r)
            
            if matches == 0:
                for i in range(6):
                    blacklists[i].append(key[i])
                # print(blacklists)
            
            elif matches > 0 and matches < 6:
                candidates = []
                for i in range(n - 1):
                    count = 0
                    for j in range(6):
                        if words[i][j] not in blacklists[j] and words[i][j] == key[j]:
                            count += 1
                    if count >= matches:
                        candidates.append(words[i])
                            
                words = candidates.copy()
                # print(words)
            
            k += 1

# Brute Force
# O(S * T); S := len(startWors); T := len(targetWords)
# TLE
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        cnt = 0
        for target in targetWords:
            for start in startWords:
                if len(target) - len(start) == 1 and len(set(list(target)) - set(list(start))) == 1:
                    cnt += 1
                    break
        return cnt

# Sort + HashSet Lookup
# O(S + T) Time
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        # Sort each start word and add it to a hash set
        startWords_sorted = set()
        # O(S*26*log(26))
        for word in startWords:
            startWords_sorted.add("".join(sorted(list(word))))
        
        # sort each target word and add it to a list
        # O(T*26*log(26))
        targetWords_sorted = []
        for word in targetWords:
            targetWords_sorted.append(sorted(list(word)))
        
        # for each sorted target word, we remove a single character and 
        # check if the resulting word is in the startWords_sorted
        # if it is, we increment cnt and break the inner loop
        # otherwise we keep removing until we either find a hit or reach the
        # end of the string
        # O(T*26) = O(T)
        cnt = 0
        for target in targetWords_sorted:
            for i in range(len(target)):
                w = target[:i] + target[i+1:]
                w = "".join(w)
                if w in startWords_sorted:
                    cnt += 1
                    break
        
        return cnt

# Using Bit Mask
# O(S + T) Time
# Similar algorithm as the one above, implemented using a bit mask to avoid the sorts
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        start_set = set()
        # O(S * 26)
        for word in startWords:
            m = 0
            for ch in word:
                i = ord(ch) - ord('a')
                m |= (1 << i)
            start_set.add(m)
        
        # O(T * 2 * 26)
        cnt = 0
        for word in targetWords:
            m = 0
            for ch in word:
                i = ord(ch) - ord('a')
                m |= (1 << i)
            
            for ch in word:
                i = ord(ch) - ord('a')
                if m ^ (1 << i) in start_set:
                    cnt += 1
                    break
        return cnt

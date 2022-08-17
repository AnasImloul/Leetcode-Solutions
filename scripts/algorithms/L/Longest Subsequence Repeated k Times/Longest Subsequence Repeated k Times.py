class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        n = len(s)
        max_chunk_sz = n // k
        
        d = collections.Counter(s)
        chars = sorted([c for c in d if d[c] >= k], reverse=True)
        if not chars:
            return ''
        
        old_cand = chars
        for m in range(2, max_chunk_sz+1):
            new_cand = []
            for t in self.get_next_level(old_cand, chars):
                if self.find(s, t*k):
                    new_cand.append(t)
            
            if len(new_cand) == 0:
                break
            old_cand = new_cand
        return old_cand[0]
        
    def get_next_level(self, cand, chars):
        for s in cand:
            for ch in chars:
                yield s + ch
        
    def find(self, s, t):
        # find subsequence t in s
        j = 0
        for i in range(len(s)):
            if s[i] == t[j]:
                j += 1
            if j == len(t):
                return True
        return False

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        # Saves some time
        if len(word1) != len(word2):
            return False
        
        from collections import Counter
        counts1 = Counter(word1)
        counts2 = Counter(word2)
        
        # No new chars can appear with operations
        if counts1.keys() != counts2.keys():
            return False
        
        # Counts can be swapped, but they will stay consistent
        if sorted(counts1.values()) != sorted(counts2.values()):
            return False
        
        return True


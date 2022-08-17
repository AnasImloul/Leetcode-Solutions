class Solution:
    def minCharacters(self, a: str, b: str) -> int:
        counter_a = Counter(ord(ch) - ord('a') for ch in a)
        counter_b = Counter(ord(ch) - ord('a') for ch in b)
        # keys will go from 0 to 25
        
        # condition 3
        # min cost to turn a consisting of single character only is len(a) - max_freq_of_character
        unique = len(a) - max(counter_a.values()) + len(b) - max(counter_b.values())
        
        a_less_than_b = b_less_than_a = len(a) + len(b)
        
        # counter maintains a prefix sum and it adds up the frequency of all previous letters upto the letter being tried as boundary letter.
        for i in range(1,26):
            counter_a[i] += counter_a[i-1]
            counter_b[i] += counter_b[i-1]
            # cost to turn a less than b
            a_less_than_b = min(a_less_than_b, len(a) - counter_a[i] + counter_b[i])
            b_less_than_a = min(b_less_than_a, len(b) - counter_b[i] + counter_a[i])
        
        

        return min(a_less_than_b, b_less_than_a, unique)
            
        ```
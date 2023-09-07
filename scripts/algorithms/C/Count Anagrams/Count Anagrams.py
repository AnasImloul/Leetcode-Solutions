# Runtime: 1882 ms (Top 30.1%) | Memory: 17.90 MB (Top 73.2%)

class Solution:
    def countAnagrams(self, s: str) -> int:

        def get(word):
            n = math.factorial(len(word))

            for v in Counter(word).values():
                n //= math.factorial(v)

            return int(n) % (10**9 + 7)

        total = 1  
        for word in s.split():
            total *= get(word)

        return total % (10**9 + 7)
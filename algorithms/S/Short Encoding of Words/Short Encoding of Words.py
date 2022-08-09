class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        """
        "time", "me", "bell" reverse() =>
        "emit", "em", "lleb" sort(reverse) =>
        "lleb"
        "emit"
        "em"
        """
        
        words = [w[::-1] for w in words]
        
        words.sort(reverse=True)
        
        res = 0
        comparable = ""
        prev_max_len = 0
        
        for w in words:
            if not comparable.startswith(w):
                res += len(w) + 1
                comparable = w
        
        return res

# Runtime: 34 ms (Top 92.91%) | Memory: 13.8 MB (Top 66.80%)

class Solution:
    def greatestLetter(self, s: str) -> str:
        cnt = Counter(s)
        return next((u for u in reversed(ascii_uppercase) if cnt[u] and cnt[u.lower()]), "")
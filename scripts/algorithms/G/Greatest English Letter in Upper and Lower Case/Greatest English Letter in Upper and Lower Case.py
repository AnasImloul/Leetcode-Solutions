class Solution:
    def greatestLetter(self, s: str) -> str:
        cnt = Counter(s)
        return next((u for u in reversed(ascii_uppercase) if cnt[u] and cnt[u.lower()]), "")

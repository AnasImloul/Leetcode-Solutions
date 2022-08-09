class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines = 1
        total = 0
        for c in s:
            total += widths[ord(c) - 97]
            if total > 100:
                lines += 1
                total = widths[ord(c) - 97]
        return [lines, total]

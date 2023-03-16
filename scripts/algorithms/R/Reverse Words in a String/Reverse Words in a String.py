class Solution:
    def split(self, s: str, delimiter=" ") -> List[str]:
        start, end = 0, 0

        res = []
        for ch in s:
            if ch == delimiter:
                if start == end:
                    start += 1
                else:
                    res.append(s[start:end])
                    start  = end + 1
            
            end += 1
        
        if start != end:
            res.append(s[start:end])

        return res

    def reverse_list(self, ll: List[str]) -> List[str]:
        l, r = 0, len(ll) - 1

        while l < r:
            ll[l], ll[r] = ll[r], ll[l]
            l += 1
            r -= 1
        
        return ll

    def reverseWords(self, s: str) -> str:

        # split first
        splitted_str_list = self.split(s)

        # reverse splitted list
        reversed_str_list = self.reverse_list(splitted_str_list)

        # join an return
        return " ".join(reversed_str_list)
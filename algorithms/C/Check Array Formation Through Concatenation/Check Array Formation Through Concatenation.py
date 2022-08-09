class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        keys, ans = {}, []
        for piece in pieces:
            keys[piece[0]] = piece
        for a in arr:
            if a in keys:
                ans.extend(keys[a])
        return ''.join(map(str, arr)) == ''.join(map(str, ans))

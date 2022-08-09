class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        return [first] + [first:= first ^ x for x in encoded]

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        hash_map = {}
        for string in arr:
            hash_map[string] = hash_map.get(string, 0) + 1
        for string in arr:
            if hash_map[string] == 1:
                k -= 1
                if k == 0:
                    return string
        return ""

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_set = list(sorted(set(arr)))
        rank = {}
        for i, e in enumerate(arr_set):
            rank[e] = i+1
        return [ rank[e] for e in arr]
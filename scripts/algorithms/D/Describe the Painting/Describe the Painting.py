class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        mix, res, last_i = DefaultDict(int), [], 0
        for start, end, color in segments:
            mix[start] += color
            mix[end] -= color
        for i in sorted(mix.keys()):
            if last_i in mix and mix[last_i]:
                res.append([last_i, i, mix[last_i]])
                mix[i] += mix[last_i]
            last_i = i
        return res

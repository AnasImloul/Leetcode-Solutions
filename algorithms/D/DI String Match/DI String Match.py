class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        result = []
        min_ = 0
        max_ = len(s)
        for x in s:
            if x=="I":
                result.append(min_)
                min_ += 1
            elif x=="D":
                result.append(max_)
                max_ -= 1
        result.append(min_)
        return result

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        beg = 0
        end = len(letters)-1
        while beg <= end:
            mid = (beg+end)//2
            if letters[mid]>target:
                end = mid -1
            else:
                beg = mid +1
        return letters[beg] if beg<len(letters) else letters[0]

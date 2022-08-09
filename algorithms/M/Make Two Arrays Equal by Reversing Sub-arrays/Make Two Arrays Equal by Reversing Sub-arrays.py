class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        target.sort()
        arr.sort()
        if len(target)==len(arr):
            if target==arr:
                return True
            else:
                return False

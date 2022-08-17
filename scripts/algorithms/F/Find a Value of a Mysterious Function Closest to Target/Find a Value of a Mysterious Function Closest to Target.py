class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        sets = [set() for _ in range(len(arr))]
        sets[0].add(arr[0])
        for i in range(1,len(arr)):
            sets[i].add(arr[i])
            for e in sets[i-1]:
                sets[i].add(e & arr[i])
        res = float('inf')
        for S in sets:
            for e in S:
                res = min(res, abs(e-target))
        return res
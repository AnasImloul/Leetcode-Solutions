class Solution:       
    def kIncreasing(self, arr: List[int], k: int) -> int:
        def LNDS(arr: List[int]) -> int:
            mono = []
            for n in arr:
                if not mono or mono[-1] <= n:
                    mono.append(n)
                else:
                    mono[bisect_right(mono, n)] = n
            return len(mono)         
        return len(arr) - sum(LNDS(arr[i::k]) for i in range(k))

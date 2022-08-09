class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        total = sum(arr)
        if total % 3 != 0:
            return False
        ave = total // 3
        stage = 0
        add = 0
        for i in arr[:-1]:
            add += i
            if add == ave:
                stage +=1
                add = 0
            if stage == 2:
                return True
        return False

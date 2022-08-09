class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        count = 0
        for i in range(0, len(row)-2, 2):
            idx = i+1
            if(row[i]%2 == 0):
                n = (row[i] + 2)//2
                newNo = 2*n - 1
            else:
                n = (row[i] + 1) //2;
                newNo = 2*n - 2
            for j in range(i, len(row)):
                if row[j] == newNo:
                    idx = j
                    break
            if idx != i+1:
                count += 1
            row[idx], row[i+1] = row[i+1], row[idx]
        return count
		```
class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        matrix = []
        for row in range(len(rowSum)):
            data, array = rowSum[row], []
            for col in range(len(colSum)):
                if data == 0 or colSum[col] == 0:
                    array.append(0)
                elif data > colSum[col]:
                    data -= colSum[col]
                    array.append(colSum[col])
                    colSum[col] = 0
                else:
                    array.append(data)
                    colSum[col] -= data
                    data = 0
            matrix.append(array)

        return matrix
                    
                    








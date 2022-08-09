class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        import numpy as np
        
        matrix = np.array(matrix, dtype=np.int32)
        
        M,N = matrix.shape
        
        ret = float("-inf")
        
        CUM = np.zeros((M,N), dtype=np.int32)
        for shift_r in range(M):
            CUM[:M-shift_r] += matrix[shift_r:]
            
            _CUM = np.zeros((M-shift_r,N), dtype=np.int32)
            for shift_c in range(N):
                _CUM[:, :N-shift_c] += CUM[:M-shift_r,shift_c:]
                tmp = _CUM[(_CUM<=k) & (_CUM>ret)]
                if tmp.size:
                    ret = tmp.max()
            if ret == k:
                return ret
        
        return ret

'''

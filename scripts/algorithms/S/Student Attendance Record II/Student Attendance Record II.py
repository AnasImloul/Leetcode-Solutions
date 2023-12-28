// Runtime: 228 ms (Top 90.78%) | Memory: 35.80 MB (Top 36.89%)

import numpy as np

class Solution:
    
    def checkRecord(self, n: int) -> int:
        MODULUS = 10**9 + 7

        initial_counts = np.array(
            [1, 0, 0, 0, 0, 0], 
            dtype=np.int64
        )

        adjacency_matrix = np.array([
            [1, 1, 1, 0, 0, 0],
            [1, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [1, 1, 1, 1, 1, 1],
            [0, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 1, 0],
        ], dtype=np.int64)

        def power(A, exp):
            B = np.identity(len(A), dtype=np.int64)
            for bit in reversed(bin(exp)[2:]):
                if bit == '1':
                    B = B @ A
                    B %= MODULUS
                A = A @ A
                A %= MODULUS
            return B

        final_counts = power(adjacency_matrix, n) @ initial_counts

        return sum(final_counts) % MODULUS

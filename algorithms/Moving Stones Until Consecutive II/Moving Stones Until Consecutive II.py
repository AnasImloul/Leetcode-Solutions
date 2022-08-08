class Solution:
    def numMovesStonesII(self, stones: list[int]) -> list[int]:
        """
        1. For the higher bound, it is determined by either moving the leftmost
            to the right side, or by moving the rightmost to the left side:
            1.1 If moving leftmost to the right side, the available moving
                positions are A[n - 1] - A[1] + 1 - (n - 1) = 
                A[n - 1] - A[1] - n + 2
            1.2 If moving rightmost to the left side, the available moving
                positions are A[n - 2] - A[0] + 1 - (n - 1) = 
                A[n - 2] - A[0] - n + 2.
        2. For the lower bound, we could use sliding window to find a window
            that contains the most consecutive stones (A[i] - A[i - 1] = 1):
            2.1 Generally the moves we need are the same as the number of
                missing stones in the current window.
            2.3 When the window is already consecutive and contains all the
                n - 1 stones, we need at least 2 steps to move the last stone
                into the current window. For example, 1,2,3,4,10:
                2.3.1 We need to move 1 to 6 first as we are not allowed to
                    move 10 to 5 as it will still be an endpoint stone.
                2.3.2 Then we need to move 10 to 5 and now the window becomes
                    2,3,4,5,6.
        """
        A, N = sorted(stones), len(stones)
        maxMoves = max(A[N - 1] - A[1] - N + 2, A[N - 2] - A[0] - N + 2)
        minMoves = N

        # Calculate minimum moves through sliding window.
        start = 0
        for end in range(N):
            while A[end] - A[start] + 1 > N:
                start += 1

            if end - start + 1 == N - 1 and A[end] - A[start] + 1 == N - 1:
                # Case: N - 1 stones with N - 1 positions.
                minMoves = min(minMoves, 2)
            else:
                minMoves = min(minMoves, N - (end - start + 1))

        return [minMoves, maxMoves]

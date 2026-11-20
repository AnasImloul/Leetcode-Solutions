# Runtime: 317 ms (Top 9.47%) | Memory: 50.90 MB (Top 5.35%)

class Solution:
    def maximumSumOfHeights(self, A: List[int]) -> int:
        n = len(A)

        def make(A):
            ans = [0]
            stack = []
            total = 0
            for i in range(n):
                width = 1
                while stack and A[i] <= A[stack[-1][0]]:
                    i0, w0 = stack.pop()
                    total -= A[i0] * w0
                    width += w0

                stack.append([i, width])
                total += A[i] * width
                ans.append(total)

            return ans

        left = make(A)
        right = make(A[::-1])[::-1]
        return max(left[i] + right[i] for i in range(n + 1))

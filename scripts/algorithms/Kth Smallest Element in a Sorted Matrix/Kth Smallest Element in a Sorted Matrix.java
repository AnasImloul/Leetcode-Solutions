/**
 * Using PriorityQueue
 *
 * Time Complexity:
 *      O(min(N,K)*log(min(N,K))) -> To add initial min(N,K) elements, as we are adding the elements individually.
 *                                   If we were adding all elements in one go, then the complexity would be O(min(N,K))
 *                                   Refer: https://stackoverflow.com/a/34697891
 *      O(2*(K-1)*log(min(N,K)) -> To poll K-1 elements and add next K-1 elements.
 * Total Time Complexity: O((min(N,K) + 2*(K-1)) * log(min(N,K)) = O(K * log(min(N,K))
 *
 * Space Complexity: O(min(N, K))
 *
 * N = Length of one side of the matrix. K = input value k.
 */
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        if (matrix == null || k <= 0) {
            throw new IllegalArgumentException("Input is invalid");
        }

        int n = matrix.length;
        if (k > n * n) {
            throw new NoSuchElementException("k is greater than number of elements in matrix");
        }
        if (k == 1) {
            return matrix[0][0];
        }
        if (k == n * n) {
            return matrix[n - 1][n - 1];
        }

        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> (matrix[a[0]][a[1]] - matrix[b[0]][b[1]]));

        for (int i = 0; i < Math.min(n, k); i++) {
            queue.offer(new int[] { i, 0 });
        }
        while (k > 1) {
            int[] cur = queue.poll();
            if (cur[1] < n - 1) {
                cur[1]++;
                queue.offer(cur);
            }
            k--;
        }

        return matrix[queue.peek()[0]][queue.peek()[1]];
    }
}

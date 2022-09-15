// Runtime: 50 ms (Top 42.43%) | Memory: 56.3 MB (Top 78.21%)
class Solution {

    private int[] prefixSum;
    private Random random;

    public Solution(int[] w) {
        for (int i = 1; i < w.length; i++)
            w[i] += w[i - 1];
        prefixSum = w;
        random = new Random();
    }

    public int pickIndex() {
        int num = 1 + random.nextInt(prefixSum[prefixSum.length - 1]); // Generate random number between 1 and total sum of weights
        int left = 0;
        int right = prefixSum.length - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (num == prefixSum[mid])
                return mid;
            else if (num < prefixSum[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
}
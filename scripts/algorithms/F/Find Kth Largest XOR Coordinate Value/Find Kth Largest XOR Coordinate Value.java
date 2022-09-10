// Runtime: 56 ms (Top 96.62%) | Memory: 250.3 MB (Top 62.84%)
class Solution {

    private static final Random RAND = new Random(0);

    public int kthLargestValue(int[][] matrix, int k) {
        var xor = convertToXorArray(matrix);
        var targetIdx = xor.length - k;
        sortPartially(xor, targetIdx, 0, xor.length);
        return xor[targetIdx];
    }

    void sortPartially(int[] nums, int targetIdx, int origLo, int origHi) {
        if (origHi - origLo < 2)
            return;

        var pivotIdx = RAND.nextInt(origHi - origLo) + origLo;
        var pivot = nums[pivotIdx];
        swap(nums, origLo, pivotIdx);

        var lo = origLo;
        var mid = lo + 1;
        var hi = origHi;
        while (mid < hi) {
            if (pivot < nums[mid])
                swap(nums, mid, --hi);
            else if (pivot > nums[mid])
                swap(nums, mid++, lo++);
            else
                mid++;
        }

        if (targetIdx < lo)
            sortPartially(nums, targetIdx, origLo, lo);

        sortPartially(nums, targetIdx, mid, origHi);
    }

    void swap(int[] n, int p, int q) {
        var tmp = n[p];
        n[p] = n[q];
        n[q] = tmp;
    }

    int[] convertToXorArray(int[][] matrix) {
        var rows = matrix.length;
        var cols = matrix[0].length;
        var xor = new int[rows * cols];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                var xIdx = r * cols + c;
                xor[xIdx] = matrix[r][c];
                if (c > 0)
                    xor[xIdx] ^= xor[xIdx - 1];
            }
        }

        for (int i = cols; i < xor.length; i++)
            xor[i] ^= xor[i - cols];

        return xor;
    }
}
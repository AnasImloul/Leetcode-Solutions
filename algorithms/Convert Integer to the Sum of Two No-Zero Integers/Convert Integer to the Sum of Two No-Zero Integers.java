class Solution {
    public int[] getNoZeroIntegers(int n) {
        int B;
        for (int A = 1; A < n; ++A) {
            B = n - A;
            if (!(A + "").contains("0") && !(B + "").contains("0"))
            return new int[] {A, B};
    }
        return new int[]{};
}
}

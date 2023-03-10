// 0 ms. 100%
class Solution {
    private static final double EPS = 1e-6;
    private boolean backtrack(double[] A, int n) {
        if(n == 1) return Math.abs(A[0] - 24) < EPS;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double a = A[i], b = A[j];
                A[j] = A[n-1];
                A[i] = a + b;
                if(backtrack(A, n - 1)) return true;
                A[i] = a - b;
                if(backtrack(A, n - 1)) return true;
                A[i] = b - a;
                if(backtrack(A, n - 1)) return true;
                A[i] = a * b;
                if(backtrack(A, n - 1)) return true;
                if(Math.abs(b) > EPS) {
                    A[i] = a / b;
                    if(backtrack(A, n - 1)) return true;
                }
                if(Math.abs(a) > EPS) {
                    A[i] = b / a;
                    if(backtrack(A, n - 1)) return true;
                }
                A[i] = a; A[j] = b;
            }
        }
        return false;
    }
    public boolean judgePoint24(int[] nums) {
        double[] A = new double[nums.length];
        for(int i = 0; i < nums.length; i++) A[i] = nums[i];
        return backtrack(A, A.length);
    }
}
// Runtime: 26 ms (Top 25.39%) | Memory: 41.4 MB (Top 78.10%)
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int total = 0;
        for (int i = 0; i < arr.length - 2; i++){
            for (int j = i+1; j < arr.length - 1; j++){
                for (int k = j+1; k < arr.length; k++){
                    if (helper(arr[i], arr[j]) <= a &&
                            helper(arr[j], arr[k]) <= b &&
                                helper(arr[k], arr[i]) <= c)
                        total++;
                }
            }
        }
        return total;
    }

    private static int helper(int x, int y) {
        return Math.abs(x - y);
    }
}
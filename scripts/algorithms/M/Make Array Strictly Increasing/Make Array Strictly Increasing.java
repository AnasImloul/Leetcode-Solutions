// Runtime: 329 ms (Top 20.6%) | Memory: 44.12 MB (Top 82.6%)

class Solution {
    public int makeArrayIncreasing(int[] A, int[] B) { // A = arr1, B = arr2
        TreeSet<Integer> set = new TreeSet<>(Arrays.stream(B).boxed().toList());
        int[] dp = new int[B.length+1];
        dp[0]=-1;
        int INF = (int)2e9;
        for (int i = 0; i < A.length; i++){
            for (int j = B.length; j >= 0; j--){
                int a = A[i] > dp[j]? A[i] : INF; // option A - don't swap
                Integer b = set.higher(j==0?INF:dp[j-1]); // option B - swap
                dp[j]=Math.min(a, b==null?INF:b); // take the min of A and B
            }
        }
        for (int i = 0; i <= B.length; i++) if (dp[i] != INF){
            return i;
        }
        return -1;
    }
}
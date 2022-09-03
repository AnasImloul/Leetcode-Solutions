// Runtime: 15 ms (Top 33.52%) | Memory: 58.1 MB (Top 8.52%)
class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {

        //1. remove the modulas -
        //i & j are interchangable because they are inside the modulas
        // A[i] - A[j] + B[i] -B[j] + i-j
        // A[i] + B[i] + i - B[j] - A[j] - j
        // (A[i] + B[i] + i) ->X
        // (B[j] - A[j] - j) -> y
        // X - Y;
        //to get max value X should be max & Y should min

        // Possible cases (Since both arrays have same number of indexes, we can use single for loop & i as index)
        //A[i] + B[i] + i ->1
        //A[i] - B[i] + i ->2
        //A[i] + B[i] - i ->3
        //A[i] - B[i] - i ->4

        // Find out max of all response

        int arrayLength =arr1.length;
        int v1[] = new int [arrayLength];
        int v2[] = new int [arrayLength] ;
        int v3[] = new int [arrayLength] ;
        int v4[] = new int [arrayLength] ;
        int res = 0;
        for(int i = 0 ; i< arrayLength; i++)
        {
            v1[i] = i + arr1[i] + arr2[i];
            v2[i] = i + arr1[i] - arr2[i];
            v3[i] = i - arr1[i] + arr2[i];
            v4[i] = i - arr1[i] - arr2[i];
        }
res = Math.max(res,Arrays.stream(v1).max().getAsInt()-Arrays.stream(v1).min().getAsInt());
                res = Math.max(res,Arrays.stream(v2).max().getAsInt()-Arrays.stream(v2).min().getAsInt());
                res = Math.max(res,Arrays.stream(v3).max().getAsInt()-Arrays.stream(v3).min().getAsInt());
                res = Math.max(res,Arrays.stream(v4).max().getAsInt()-Arrays.stream(v4).min().getAsInt());
    return res;
    }
}
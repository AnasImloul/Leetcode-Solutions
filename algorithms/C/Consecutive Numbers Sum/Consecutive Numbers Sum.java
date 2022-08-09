class Solution {

    public int consecutiveNumbersSum(int n) {
	    final double eightN = (8d * ((double) n)); // convert to double because 8n can overflow int
        final int maxTriangular = (int) Math.floor((-1d + Math.sqrt(1d + eightN)) / 2d);
        int ways = 1;
        int triangular = 1;
        for (int m = 2; m <= maxTriangular; ++m) {
            triangular += m;
            final int difference = n - triangular;
            if ((difference % m) == 0) {
                ways++;
            }
        }
        return ways;
    }

}

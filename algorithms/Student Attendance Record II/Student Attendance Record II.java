class Solution {

    private static final int MOD = (int) Math.pow(10, 9) + 7;

    public int checkRecord(int n) {

        return (int) checkRecord(n, 0, 0, new Integer[n + 1][3][2]);
    }

    public int checkRecord(int n, int leaveCount, int absentCount, Integer[][][] memo) {

        if (memo[n][leaveCount][absentCount] != null) return memo[n][leaveCount][absentCount];

        if (n == 0) return 1;

        int recordCount = 0;

        // Add P
        recordCount += checkRecord(n - 1, 0, absentCount, memo);
        recordCount = recordCount % MOD;

        // Add L
        if (leaveCount < 2) {
            recordCount += checkRecord(n - 1, leaveCount + 1, absentCount, memo);
            recordCount = recordCount % MOD;
        }

        // Add A
        if (absentCount < 1) {
            recordCount += checkRecord(n - 1, 0, 1, memo);
            recordCount = recordCount % MOD;
        }

        memo[n][leaveCount][absentCount] = recordCount;
        return recordCount;
    }
}

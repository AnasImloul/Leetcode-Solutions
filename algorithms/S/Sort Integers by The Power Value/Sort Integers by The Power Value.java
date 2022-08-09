class Solution {
    public int getKth(int lo, int hi, int k) {

        int p = 0;
        int[][] powerArr = new int[hi - lo + 1][2];

        Map<Integer, Integer> memo = new HashMap<>();
        for (int i = lo; i <= hi; i++)
            powerArr[p++] = new int[]{i, getPower(i, memo)};

        Arrays.sort(powerArr, (a1, a2) -> a1[1] - a2[1] == 0 ? a1[0] - a2[0] : a1[1] - a2[1]);

        return powerArr[k - 1][0];
    }

    private int getPower(int i, Map<Integer, Integer> memo) {
        if (memo.containsKey(i)) return memo.get(i);

        if (i == 1) return 0;

        int power = 1 + (i % 2 == 0 ? getPower(i / 2, memo) : getPower(i * 3 + 1, memo));

        memo.put(i, power);
        return power;
    }
}

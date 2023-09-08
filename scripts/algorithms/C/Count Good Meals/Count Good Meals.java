// Runtime: 160 ms (Top 78.2%) | Memory: 55.21 MB (Top 66.3%)

class Solution {
    int mod = 1000000007;
    public int countPairs(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = arr.length;
        long res = 0;
        for (int num : arr) {
            int power = 1;
            for (int i = 0; i < 22; i++) {
                if (map.containsKey(power - num)) {
                    res += map.get(power - num);
                    res %= mod;
                }
                power *= 2;
            }
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        return (int) res;
    }
}
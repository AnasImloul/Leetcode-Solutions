// Runtime: 8 ms (Top 41.3%) | Memory: 44.12 MB (Top 6.5%)

class Solution {
    public boolean divideArray(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i : arr) map.put(i, map.getOrDefault(i, 0) + 1);
        for (int i : map.keySet()) {
            if (map.get(i) % 2 != 0) return false;
        }
        return true;
    }
}
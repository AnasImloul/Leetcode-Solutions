// Runtime: 204 ms (Top 31.03%) | Memory: 131.5 MB (Top 7.83%)
class Solution {
public int[] fullBloomFlowers(int[][] flowers, int[] persons) {
        int n = persons.length;
        int[] result = new int[n];

        TreeMap<Integer, Integer> treeMap = new TreeMap<>();
        // See explanation here: https://leetcode.com/problems/my-calendar-iii/discuss/109556/JavaC%2B%2B-Clean-Code
        for (int[] flower : flowers) {
            treeMap.put(flower[0], treeMap.getOrDefault(flower[0], 0) + 1);
            // use end + 1 instead of end
            treeMap.put(flower[1] + 1, treeMap.getOrDefault(flower[1] + 1, 0) - 1);
        }

        TreeMap<Integer, Integer> sum = new TreeMap<>();
        int prev = 0;
        for (Map.Entry<Integer, Integer> entry : treeMap.entrySet()) {
            prev += entry.getValue();
            sum.put(entry.getKey(), prev);
        }

        for (int i = 0; i < n; i++) {
            Map.Entry<Integer, Integer> entry = sum.floorEntry(persons[i]);
            // if entry is null then result[i] = 0
            if (entry != null) result[i] = entry.getValue();
        }
        return result;
    }
}
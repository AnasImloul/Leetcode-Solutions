// Runtime: 61 ms (Top 63.76%) | Memory: 95 MB (Top 59.07%)
class Solution {
    public int totalFruit(int[] fruits) {
        if (fruits == null || fruits.length == 0) {
            return 0;
        }
        int start = 0, end = 0, res = 0;
        HashMap<Integer, Integer> map = new HashMap<>(); //key = type of fruit on tree, value = last index / newest index of that fruit

        while (end < fruits.length) {
            if (map.size() <= 2) {
                map.put(fruits[end], end);
                end++;
            }

            if (map.size() > 2) {
                int leftMost = fruits.length;
                for (int num : map.values()) {
                    leftMost = Math.min(leftMost, num);
                }
                map.remove(fruits[leftMost]);
                start = leftMost + 1;
            }

            res = Math.max(res, end - start);
        }
        return res;
    }
}
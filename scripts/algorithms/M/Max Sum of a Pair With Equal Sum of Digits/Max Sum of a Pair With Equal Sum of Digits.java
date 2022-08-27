// Runtime: 125 ms (Top 33.41%) | Memory: 82.2 MB (Top 27.68%)
class Solution {
    public int maximumSum(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int result = -1;

        for (int item : nums) {
            int key = getNumberTotal(item);

            if (!map.containsKey(key))
                map.put(key, item);
            else {
                result = Math.max(result, map.get(key) + item);
                map.put(key, Math.max(map.get(key), item));
            }
        }

        return result;
    }

    int getNumberTotal(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }

        return result;
    }
}
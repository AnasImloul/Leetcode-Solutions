class Solution {
     public int findSpecialInteger(int[] arr) {
        if (arr.length == 1) {
            return arr[0];
        }
        int count = (int) Math.ceil(arr.length / 4);
        System.out.println(count);

        Map<Integer, Integer> map = new HashMap<>();

        for (Integer i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
            if (map.get(i) > count) {
                return i;
            }
        }
        return -1;
    }
}

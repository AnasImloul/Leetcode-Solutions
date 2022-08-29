// Runtime: 7 ms (Top 17.72%) | Memory: 48.7 MB (Top 54.45%)
class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        int[] arr = new int[k];
        for (int i = 0; i < mat.length; i++){
            int n = getBits(mat[i]);
            map.put(i, n);
            list.add(n);
        }
        Collections.sort(list);
        int z = 0;
        for (int i = 0; i < k; i++){
            for (Map.Entry<Integer, Integer> m : map.entrySet()){
                if (list.get(i).equals(m.getValue())){
                    arr[z++] = m.getKey();
                    map.remove(m.getKey(), m.getValue());
                    break;
                }
            }
        }

        return arr;
    }

    private static Integer getBits(int[] arr) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 1) count++;
        }

        return count;
    }
}
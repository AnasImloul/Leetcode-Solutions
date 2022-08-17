class Solution {
    public int countPairs(int[] deliciousness) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : deliciousness){ // freq table
            map.merge(n, 1, Integer::sum);
        }

        long ans = 0;
        for (int key : map.keySet()){
            int i = 1, cur = map.get(key);
            while(key > i - key) i <<= 1; // only check those no less than the current key number
            while(i <= (1 << 21)){
                ans += (key != i - key? 
                        1L * cur * map.getOrDefault(i - key, 0) : // choose one from each pile
                       (1L * cur * (cur - 1)) / 2); // edge case -> choose two from the same pile 
                i <<= 1;
            }
        }

        return (int)(ans % (int)(1e9+7));
    }
}

// The last test case fails and gives a TLE
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int res[] = new int[n];
        Map<Integer, Integer> map = new HashMap<>();
        int copy[] = new int[n];
        int ind = 0;
        for(int p : arr){
            copy[ind++] = p;
        }
        Arrays.sort(copy);
        List<Integer> set = new ArrayList<>();
        for(int k : copy){
            if(!set.contains(k)){
                set.add(k);
            }
        }
        for(int i = 0;i<set.size();i++){
            map.put(set.get(i), i+1);
        }
        ind = 0;
        for(int p : arr){
            res[ind++] = map.get(p);
        }
        return res;
    }
}

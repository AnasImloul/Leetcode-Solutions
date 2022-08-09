class Solution {
    public int kthFactor(int n, int k) {
    ArrayList<Integer> list = new ArrayList<>();

        for (int i = 1; i <= n; i++) {

            if (n % i == 0){
                list.add(i);
            }
        }
        if (list.size() < k){
            return -1;
        }
        
        return list.get(k-1);
    }
}

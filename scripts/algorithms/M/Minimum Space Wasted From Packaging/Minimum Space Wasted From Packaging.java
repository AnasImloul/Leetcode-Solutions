class Solution {
    public int minWastedSpace(int[] packages, int[][] boxes) {
        Arrays.sort(packages);
        int n = packages.length, k = -1;
        long sum = 0, ans = Long.MAX_VALUE;
        int[] pos = new int[100001];
        for (int i = 0; i < 100001; i++){ // precompute jump position.
            while(k < n - 1 && packages[k+1] == i){
                sum += packages[++k];
            }
            pos[i] = k;
        }
        for (int[] b : boxes){
            Arrays.sort(b);
            long cost = -sum;
            k=-1;
            for (int i = 0; i < b.length; i++){
                if (pos[b[i]] >= 0){
                    int cnt = pos[b[i]]-k;
                    cost += 1L * cnt * b[i];
                    k=pos[b[i]];
                }
            }
            ans = k == n-1? Math.min(cost, ans) : ans;
        }

        return ans == Long.MAX_VALUE? -1 : (int)(ans % (int)(1e9+7));
    }
}

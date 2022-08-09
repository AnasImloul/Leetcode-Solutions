class Solution {
    int M = (int)1e9+7;
    public int waysToBuildRooms(int[] prevRoom) {
        int n = prevRoom.length;
        long[] fact = new long[n];
        long[] invFact = new long[n];
        long[] inv = new long[n];
        fact[1]=fact[0]=invFact[0]=invFact[1]=inv[1]=1;
        for (int i = 2; i < n; i++){ // modInverse 
            fact[i] = fact[i-1]*i%M;
            inv[i] = M-M/i*inv[M%i]%M;
            invFact[i] = invFact[i-1]*inv[i]%M;
        }

        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++){ // add an edge from parent to child
            map.computeIfAbsent(prevRoom[i], o -> new ArrayList<>()).add(i);
        }

        long[] ans = new long[]{1};
        solve(0, fact, invFact, map, ans);
        return (int)ans[0];
    }

    private int solve(int i, long[] fact, long[] invFact, Map<Integer, List<Integer>> map, long[] ans){
        int sum = 0;
        for (int next : map.getOrDefault(i, List.of())){
            int cur = solve(next, fact, invFact, map, ans);
            ans[0] = ans[0] * invFact[cur] % M; // divide fact[cur] -> multiply invFact[cur]
            sum += cur;
        }
        ans[0] = ans[0] * fact[sum] % M;
        return sum+1;
    }
}

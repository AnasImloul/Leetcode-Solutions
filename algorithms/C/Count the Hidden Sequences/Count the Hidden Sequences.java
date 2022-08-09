class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(lower); 
        int mn = lower;
        int mx = lower;
        
        for (int i = 0; i < differences.length; i++) {
            int d = differences[i];
            ans.add(d + ans.get(ans.size() - 1));
            mn = Math.min(mn, ans.get(ans.size() - 1));
            mx = Math.max(mx, ans.get(ans.size() - 1));
        }

        int add = lower - mn;
        
        for (int i = 0; i < ans.size(); i++) {
            ans.set(i, ans.get(i) + add);
        }
        
        for (int i = 0; i < ans.size(); i++) {
            if (ans.get(i) < lower ||  upper < ans.get(i)) {
                return 0;
            }
        }
        
        int add2 = upper - mx;
        
        return add2 - add + 1;
    }
}

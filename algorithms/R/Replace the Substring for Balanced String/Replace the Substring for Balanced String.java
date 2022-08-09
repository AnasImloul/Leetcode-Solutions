class Solution {
    public int balancedString(String s) {
        int n = s.length(), ans = n, excess = 0;
        int[] cnt = new int[128];
        cnt['Q'] = cnt['W'] = cnt['E'] = cnt['R'] = -n/4;
        for (char ch : s.toCharArray()) if (++cnt[ch] == 1) excess++; //if count reaches 1, it is extra and to be removed.
        if (excess == 0) return 0;
        for (int i = 0, j = 0; i < n; i++){//i = window right end, j = window left end
            if (--cnt[s.charAt(i)] == 0) excess--; //remove letter at index i
            while (excess == 0){ //if no more excess, then 
                if (++cnt[s.charAt(j)] == 1) excess++; //we put letter at index j back
                ans = Math.min(i - j + 1, ans);; //and update ans accordingly
                j++;
            }
        }

        return ans;
    }
}

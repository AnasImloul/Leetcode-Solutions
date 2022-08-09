class Solution {
    int mod = (1000000007);

    public int countTexts(String pressedKeys) {
        int[] key = new int[] { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
        int n = pressedKeys.length();
        return solve(0,pressedKeys,key);
    }

    public int solve(int ind, String s, int[] key) {
        if (ind == s.length()) {
            return 1;
        }
        int count = 0;
        int num = s.charAt(ind) - '0';
        int rep = key[num];
        for (int i = 0; i < rep && ind + i < s.length() && s.charAt(ind) == s.charAt(ind + i); i++) {
            count += solve(ind + 1 + i, s, key);
            count %= mod;
        }
        return  count;
    }
}

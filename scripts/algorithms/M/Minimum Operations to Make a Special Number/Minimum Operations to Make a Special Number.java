// Runtime: 1 ms (Top 100.0%) | Memory: 42.00 MB (Top 31.4%)

class Solution {
    public int check(String num, int i) {
        for (int j = i - 1; j >= 0; j--) {
            int t = (num.charAt(i) - '0') + (num.charAt(j) - '0') * 10;
            if (t % 25 == 0) return num.length() - j - 2;
        }
        return num.length();
    }

    public int minimumOperations(String num) {
        int n = num.length(), ans = n, i;
        for (i = n - 1; i >= 0 && num.charAt(i) != '0'; i--);
        if (i >= 0) ans = Math.min(n - 1, check(num, i));
        for (i = n - 1; i >= 0 && num.charAt(i) != '5'; i--);
        return Math.min(ans, check(num, i));
    }
}

class Solution {
    public String thousandSeparator(int n) {
        if (n == 0) return String.valueOf(0);

        String ans = "";
        int count = 0;
        for (int i = n; i != 0; i /= 10, count++){
            int r = i % 10;
            if (count == 3){
                ans += "." + r;
                count = 0;
            }
            else ans += r;
        }

        return reverse(ans);
    }

    private static String reverse(String s) {
        String ans = "";
        for (int i = s.length() - 1; i >= 0; i--){
            ans += s.charAt(i);
        }
        return ans;
    }
}

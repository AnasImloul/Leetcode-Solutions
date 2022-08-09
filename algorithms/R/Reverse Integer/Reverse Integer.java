class Solution {
    public int reverse(int x) {
        if (x > 2147483647 || x < -2147483648) return 0;
        String num = "";
        boolean neg = false;
        if (x < 0) {
            neg = true;
            x = -x;
        }
        while(x > 0) {
            num += Integer.toString(x % 10);
            x /= 10;
        }
        if (num.length() < 10) {
            int diff = 10 - num.length();
            while(diff>=0) {
                num = "0" + num;
                diff--;
            }
        }
        System.out.println(num + " " + num.compareTo("2147483647"));
        if (num.compareTo("2147483647") > 0) return 0;
        else if (neg) return -Integer.parseInt(num);
        else return Integer.parseInt(num);
    }
}

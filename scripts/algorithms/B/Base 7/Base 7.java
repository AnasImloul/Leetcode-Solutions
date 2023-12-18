// Runtime: 1 ms (Top 62.45%) | Memory: 40.70 MB (Top 12.35%)

class Solution {
    public String convertToBase7(int num) {
        StringBuilder sb = new StringBuilder();
        while(Math.abs(num) > 6) {
            sb.append(num % 7);
            num = num / 7;
        }
        if (num < 0) {
            sb.append(Math.abs(num)).append("-");
        } else {
            sb.append(num);
        }
        for (int i = 0; i < sb.length() - 1; i++) {
            if (!Character.isDigit(sb.charAt(i))) {
                sb.replace(i, i + 1, "");
            }
        }
        return sb.reverse().toString();
    }
}

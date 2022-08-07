class Solution {
    public String convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        int temp = num;
        if (temp < 0) {
            temp = -temp;
        }
        while (temp > 0) {
            int rem = temp % 7;
            sb.append(rem);
            temp = temp / 7;
        }
        if (num < 0) {
            sb.append("-");
        }
        return sb.reverse().toString();
    }
}

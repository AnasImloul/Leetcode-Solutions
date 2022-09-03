// Runtime: 0 ms (Top 100.00%) | Memory: 41.4 MB (Top 60.13%)
class Solution {
    public String toHex(int num) {
        if(num == 0) return "0";

        boolean start = true;

        StringBuilder sb = new StringBuilder();

        for(int i = 28; i >= 0; i -= 4) {
            int digit = (num >> i) & 15;
            if(digit > 9) {
                char curr = (char)(digit%10 + 'a');
                sb.append(curr);
                start = false;
            } else if(digit != 0) {
                char curr = (char)(digit + '0');
                sb.append(curr);
                start = false;
            } else {//digit == 0
                if(start == false) { //avoid case: 00001a
                    sb.append('0');
                }
            }

        }
        return sb.toString();
    }
}
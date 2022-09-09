// Runtime: 1 ms (Top 90.03%) | Memory: 41.4 MB (Top 67.52%)
class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder sb = new StringBuilder();
        int x = Math.min(a, Math.min(b, Math.abs(a - b))); // TAKE THE MIN OF (a, b, abs(a - b))
        if (a > b){
            sb.append("aab".repeat(x));
            b -= x;
            a -= 2 * x;
        }
        if (a < b){
            sb.append("bba".repeat(x));
            b -= 2 * x;
            a -= x;
        }
        if (a == b){
            sb.append("ab".repeat(a));
        }
        if (a == 0){
            sb.append("b".repeat(b));
        }
        if (b == 0){
            sb.append("a".repeat(a));
        }
        return sb.toString();
    }
}
class Solution {
    public String baseNeg2(int n) {
        StringBuilder answer = new StringBuilder(n == 0 ? "0" : "" );
        for(;n!=0;n=-(n>>1)) {
            answer.append((n&1) == 0 ? '0' : '1' );
        }
        return answer.reverse().toString();
    }
}

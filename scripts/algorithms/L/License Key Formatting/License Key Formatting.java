// Runtime: 26 ms (Top 55.76%) | Memory: 45.6 MB (Top 53.19%)
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder answer = new StringBuilder();
        int length = 0;
        // Iterate Backwards to fullfill first group condition
        for(int i=s.length()-1;i>=0;i--) {
            if(s.charAt(i) == '-') {
                continue;
            }
            if(length > 0 && length % k == 0) {
                answer.append('-');
            }
            answer.append(Character.toUpperCase(s.charAt(i)));
            length++;
        }
        return answer.reverse().toString();
    }
}
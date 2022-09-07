// Runtime: 31 ms (Top 69.83%) | Memory: 55 MB (Top 18.30%)
class Solution {
    public String removeKdigits(String num, int k) {
        int n = num.length();
        if(n == k){
            return "0";
        }
        Deque<Character> dq = new ArrayDeque<>();
        for(char ch : num.toCharArray()){
            while(!dq.isEmpty() && k > 0 && dq.peekLast() > ch){
                dq.pollLast();
                k--;
            }
            dq.addLast(ch);
        }
        StringBuilder sb = new StringBuilder();
        while(!dq.isEmpty() && dq.peekFirst() == '0'){
            dq.pollFirst();
        }
        while(!dq.isEmpty()){
            sb.append(dq.pollFirst());
        }
        if(k >= sb.length()){
            return "0";
        }
        return sb.length() == 0 ? "0" : sb.toString().substring(0,sb.length()-k);
    }
}
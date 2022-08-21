// Runtime: 3 ms (Top 87.48%) | Memory: 42.2 MB (Top 54.57%)

class Solution {
    public String smallestSubsequence(String s) {
        boolean[] inStack = new boolean [26];
        int[] lastIdx = new int [26];
        Arrays.fill(lastIdx,-1);
        for(int i = 0; i < s.length(); i++){
            lastIdx[s.charAt(i)-'a'] = i;
        }
        Deque<Character> dq = new ArrayDeque<>();
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(inStack[ch-'a']){
                continue;
            }
            while(!dq.isEmpty() && dq.peekLast() > ch && lastIdx[dq.peekLast()-'a'] > i){
                inStack[dq.pollLast()-'a'] = false;
            }
            dq.addLast(ch);
            inStack[ch-'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        while(!dq.isEmpty()){
            sb.append(dq.pollFirst());
        }
        return sb.toString();
    }
}
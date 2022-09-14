// Runtime: 405 ms (Top 56.76%) | Memory: 43.2 MB (Top 86.49%)
class Solution {
    char[] A;
    public String longestSubsequenceRepeatedK(String s, int k) {
        A = s.toCharArray();
        Queue<String> queue = new ArrayDeque<>();
        queue.offer("");
        String ans = "";
        int[] count = new int[26];
        BitSet bit = new BitSet();
        for (char ch : A) if (++count[ch-'a'] >= k){
            bit.set(ch-'a');
        }
        while(!queue.isEmpty()){
            String sb = queue.poll();
            for (int i = bit.nextSetBit(0); i >= 0; i = bit.nextSetBit(i+1)){
                String res = sb+(char)(i+'a');
                if (check(k, res)){
                    ans = res;
                    queue.offer(res);
                }
            }
        }
        return ans;
    }

    private boolean check(int k, String s){
        int cnt = 0;
        for (char ch : A){
            if (s.charAt(cnt%s.length()) == ch && ++cnt >= k * s.length()){
                return true;
            }
        }
        return false;
    }
}
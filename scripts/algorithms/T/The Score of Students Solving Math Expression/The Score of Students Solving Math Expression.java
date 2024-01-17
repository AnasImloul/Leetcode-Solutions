// Runtime: 161 ms (Top 97.83%) | Memory: 45.80 MB (Top 93.48%)

class Solution {
    public int scoreOfStudents(String s, int[] answers) {
        BitSet[][] ok = new BitSet[32][32];
        solve(0, s.length()-1, s, ok);
        int ans = 0, correct = eval(s);
        for (int n : answers){
            if (correct == n){
                ans += 5;
            }else if (ok[0][s.length()-1].get(n)){
                ans += 2;
            }
        }
        return ans;
    }

    private BitSet solve(int lo, int hi, String s, BitSet[][] memo){
        if (memo[lo][hi] != null){ // memo
            return memo[lo][hi];
        }
        BitSet cur = new BitSet();
        if (lo == hi){ // base case -> number itself [0 - 9]
            cur.set(s.charAt(lo) - '0');
            return memo[lo][hi]=cur;
        }
        for (int i = lo; i <= hi; i++){
            if (s.charAt(i) == '+' || s.charAt(i) == '*'){
                BitSet l = solve(lo, i-1, s, memo); // left
                BitSet r = solve(i+1, hi, s, memo); // right
                for (int j = l.nextSetBit(0); j >= 0; j = l.nextSetBit(j+1)){
                    for (int k = r.nextSetBit(0); k >= 0; k = r.nextSetBit(k+1)){
                        int val = s.charAt(i) == '+'? j+k:j*k;
                        if (val > 1000){
                            break;
                        }
                        cur.set(val);
                    }
                }
            }
        }
        return memo[lo][hi]=cur;
    }

    private int eval(String s){
        Deque<Integer> stack = new ArrayDeque<>();
        Deque<Character> op = new ArrayDeque<>();
        for(char ch : s.toCharArray()){
            if (ch == '+' || ch == '*'){
                while(!op.isEmpty() && (ch == '+' || op.peek() == '*')){
                    char w = op.pop();
                    int r = stack.pop(), l = stack.pop();
                    stack.push(w == '+'? l + r : l * r);
                }
                op.push(ch);
            }else{
                stack.push(ch-'0');
            }
        }
        while(!op.isEmpty()){
            char w = op.pop();
            int r = stack.pop(), l = stack.pop();
            stack.push(w == '+'? l + r : l * r);
        }

        return stack.pop();
    }
}

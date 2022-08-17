class Solution {
    public String minInteger(String num, int k) {
        int n = num.length();
        Queue<Integer>[] q = new LinkedList[10];
        for(int i = 0; i <= 9; i++) q[i] = new LinkedList<Integer>();
        for(int i = 0; i < n; i++) q[num.charAt(i)-'0'].add(i);
        
        fenWickTree ft = new fenWickTree(n);
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < n; i++) {
            for(int d = 0; d <= 9; d++) {
                if(q[d].isEmpty()) continue;
                int pos = q[d].peek();
                int alreadyMoved = ft.getSum(pos+1);
                int reqSwaps = pos - alreadyMoved;
                if(reqSwaps <= k) {
                    k -= reqSwaps;
                    char c = (char)(d+'0');
                    ans.append(c);
                    q[d].poll();
                    ft.update(pos+1);
                    break;
                }
            }
        }
        
        return ans.toString();
    }
    
    static class fenWickTree {
        int[] tree;
        int n;
        fenWickTree(int n) {
            tree = new int[n+1];
            this.n = n;
        }
        
        public void update(int idx) {
            while(idx <= n) {
                tree[idx]++;
                idx += idx&-idx;
            }
        }
        
        public int getSum(int idx) {
            int sum = 0;
            while(idx > 0) {
                sum += tree[idx];
                idx -= idx&-idx;
            }
            
            return sum;
        }
    }
}

class Solution {
    class QueryComparator implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return Integer.compare(a[1], b[1]);
        }
    }
    
    class Node {
        Node zero;
        Node one;
        
        public Node() {
            this.zero = null;
            this.one = null;
        }
    }
    
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        
        int len = queries.length;
        int[][] queryWithIndex = new int[len][3];
        for(int i = 0; i < len; i++) {
            queryWithIndex[i][0] = queries[i][0];
            queryWithIndex[i][1] = queries[i][1];
            queryWithIndex[i][2] = i;
        }
        Arrays.sort(queryWithIndex, new QueryComparator());
        
        int numId = 0;
        int[] ans = new int[len];
        
        Node root = new Node();
        for(int i = 0; i < len; i++) {
            while(numId < nums.length && nums[numId] <= queryWithIndex[i][1]) {
                addNumToTree(nums[numId], root);
                numId++;
            }
            
            ans[queryWithIndex[i][2]] = maxXOR(queryWithIndex[i][0], root);
        }
        
        return ans;
    }
    
    private void addNumToTree(int num, Node node) {
        for(int i = 31; i >= 0; i--) {
            int digit = (num >> i) & 1;
            if (digit == 1) {
                if (node.one == null) {
                    node.one = new Node();
                }
                node = node.one;
            } else {
                if (node.zero == null) {
                    node.zero = new Node();
                }
                node = node.zero;
            }
        }
    }
    
    private int maxXOR(int num, Node node) {
        if (node.one == null && node.zero == null) {
            return -1;
        }

        int ans = 0;
        for(int i = 31; i >= 0 && node != null; i--) {
            int digit = (num >> i) & 1;
            if (digit == 1) {
                if (node.zero != null) {
                    ans += (1 << i);
                    node = node.zero;
                } else {
                    node = node.one;
                }
            } else {
                if (node.one != null) {
                    ans += (1 << i);
                    node = node.one;
                } else {
                    node = node.zero;
                }
            }
        }
        
        return ans;
    }
}

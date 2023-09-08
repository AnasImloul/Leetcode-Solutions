// Runtime: 194 ms (Top 80.8%) | Memory: 52.65 MB (Top 6.3%)

class Solution {
    public String minInteger(String num, int k) {
        //pqs stores the location of each digit.
        List<Queue<Integer>> pqs = new ArrayList<>();
        for (int i = 0; i <= 9; ++i) {
            pqs.add(new LinkedList<>());
        }

        for (int i = 0; i < num.length(); ++i) {
            pqs.get(num.charAt(i) - '0').add(i);
        }
        String ans = "";
        SegmentTree seg = new SegmentTree(num.length());

        for (int i = 0; i < num.length(); ++i) {
            // At each location, try to place 0....9
            for (int digit = 0; digit <= 9; ++digit) {
                // is there any occurrence of digit left?
                if (pqs.get(digit).size() != 0) {
                    // yes, there is a occurrence of digit at pos
                    Integer pos = pqs.get(digit).peek();
					// Since few numbers already shifted to left, this `pos` might be outdated.
                    // we try to find how many number already got shifted that were to the left of pos.
                    int shift = seg.getCountLessThan(pos);
                    // (pos - shift) is number of steps to make digit move from pos to i.
                    if (pos - shift <= k) {
                        k -= pos - shift;
                        seg.add(pos); // Add pos to our segment tree.
                        pqs.get(digit).remove();
                        ans += digit;
                        break;
                    }
                }
            }
        }
        return ans;
    }

    class SegmentTree {
        int[] nodes;
        int n;

        public SegmentTree(int max) {
            nodes = new int[4 * (max)];
            n = max;
        }

        public void add(int num) {
            addUtil(num, 0, n, 0);
        }

        private void addUtil(int num, int l, int r, int node) {
            if (num < l || num > r) {
                return;
            }
            if (l == r) {
                nodes[node]++;
                return;
            }
            int mid = (l + r) / 2;
            addUtil(num, l, mid, 2 * node + 1);
            addUtil(num, mid + 1, r, 2 * node + 2);
            nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
        }

        // Essentialy it tells count of numbers < num.
        public int getCountLessThan(int num) {
            return getUtil(0, num, 0, n, 0);
        }

        private int getUtil(int ql, int qr, int l, int r, int node) {
            if (qr < l || ql > r) return 0;
            if (ql <= l && qr >= r) {
                return nodes[node];
            }

            int mid = (l + r) / 2;
            return getUtil(ql, qr, l, mid, 2 * node + 1) + getUtil(ql, qr, mid + 1, r, 2 * node + 2);
        }
    }

}
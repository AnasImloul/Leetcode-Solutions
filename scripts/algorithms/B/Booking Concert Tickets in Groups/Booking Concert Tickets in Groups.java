// Runtime: 221 ms (Top 91.46%) | Memory: 140.4 MB (Top 35.37%)
class BookMyShow {
    /**
        Segment tree class to store sum of a range and maximum available seats in a row
    **/
    static class SegTree{
        long sum[]; // store sum of seats in a range
        long segTree[]; // store maximum seats in a range
        int m, n;
        public SegTree(int n, int m) {
            this.m = m;
            this.n = n;
            segTree = new long[4*n];
            sum = new long[4*n];
            build(0, 0, n-1, m);
        }

        private void build(int index, int lo, int hi, long val){
            if(lo == hi){
                segTree[index] = val; // initialize segement tree with initial seat capacity
                sum[index] = val; // initialize "sum" with initial seat capacity of a row
                return;
            }
            int mid = (lo + hi)/2;
            build(2*index +1, lo, mid, val); // build left sub tree
            build(2*index +2, mid+1, hi, val); // build right sub tree
            segTree[index] = Math.max(segTree[2*index + 1], segTree[2*index + 2]); // maximum seats in a row for subtrees
            sum[index] = sum[2*index + 1] + sum[2*index + 2]; // sum of seats in a range
        }

        private void update(int index, int lo, int hi, int pos, int val){
            /**
                Method to update segment tree based on the available seats in a row
            **/
            if(lo == hi){
                segTree[index] = val;
                sum[index] = val;
                return;
            }
            int mid = (lo + hi) / 2;
            if (pos <= mid) { // position to update is in left
               update(2 * index + 1, lo, mid, pos, val);
            } else { // position to update is in right
                update(2 * index + 2, mid+1, hi, pos, val);
            }
            // update segment tree and "sum" based on the update in "pos" index
            segTree[index] = Math.max(segTree[2*index + 1] , segTree[2*index + 2]);
            sum[index] = sum[2*index + 1] + sum[2*index + 2];
        }

        public void update(int pos, int val){
            update(0, 0, n - 1 , pos, val);
        }

        public int gatherQuery(int k, int maxRow){
            return gatherQuery(0, 0, n - 1 , k, maxRow);
        }

        private int gatherQuery(int index, int lo, int hi, int k, int maxRow){
            /**
                Method to check if seats are available in a single row
            **/
            if(segTree[index] < k || lo > maxRow)
                return -1;
            if(lo == hi) return lo;
            int mid = (lo + hi) / 2;
            int c = gatherQuery(2*index + 1, lo, mid, k, maxRow);
            if(c == -1){
                c = gatherQuery(2*index + 2, mid +1, hi, k, maxRow);
            }
            return c;
        }

        public long sumQuery(int k, int maxRow){
            return sumQuery(0, 0, n-1, k, maxRow);
        }

        private long sumQuery(int index, int lo, int hi, int l, int r){
            if(lo > r || hi < l ) return 0; // not in range
            if(lo >= l && hi <= r) return sum[index]; // in range
            int mid = (lo + hi)/2;
            return sumQuery(2*index+1, lo, mid, l, r) + sumQuery(2*index+2, mid+1, hi, l, r);
        }
    }

    SegTree segTree;
    int[] rowSeats; // stores avaiable seats in a row, helps to find the vacant seat in a row

    public BookMyShow(int n, int m) {
        segTree = new SegTree(n, m);
        rowSeats = new int[n];
        Arrays.fill(rowSeats, m); // initialize vacant seats count to "m" for all the rows
    }

    public int[] gather(int k, int maxRow) {
        int row = segTree.gatherQuery(k, maxRow); // find row which has k seats
        if(row == -1) return new int[]{}; // can't find a row with k seats
        int col = segTree.m - rowSeats[row]; // find column in the row which has k seats
        rowSeats[row] -= k; // reduce the seats
        segTree.update(row, rowSeats[row]); // update the segment tree
        return new int[]{row, col};

    }

    public boolean scatter(int k, int maxRow) {
        long sum = segTree.sumQuery(0, maxRow); // find the sum for the given range [0, maxRow]
        if(sum < k) return false; // can't find k seats in [0, maxRow]

        for(int i=0; i<=maxRow && k !=0 ; i++){
            if(rowSeats[i] > 0){ // if current row has seats then allocate those seats
                long t = Math.min(rowSeats[i], k);
                rowSeats[i] -= t;
                k -= t;
                segTree.update(i,rowSeats[i]); // update the segment tree
            }
        }
        return true;
    }
}
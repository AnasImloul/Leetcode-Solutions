// Runtime: 11 ms (Top 89.89%) | Memory: 46.10 MB (Top 5.62%)

class Solution {
    public List<Integer> fallingSquares(int[][] positions) {
        SegmentNode root = new SegmentNode(0,Integer.MAX_VALUE,0);
        List<Integer> ans = new ArrayList<>();
        int max = 0;
        for(int[] p : positions){
            int left = p[0], height = p[1], right = left + height;
            int maxHeight = query(root, left, right) + height;
            max = Math.max(max,maxHeight);
            ans.add(max);
            add(root, left, right, maxHeight);
        }
        return ans;
    }
    public int query(SegmentNode root, int start, int end){
        if(start<=root.start && end>=root.end) return root.maxHeight;
        if(start>=root.end || end<=root.start) return  0;
        if (root.left==null) return root.maxHeight;
        int mid = root.start + (root.end - root.start) / 2;
        if (end <= mid) {
            return query(root.left, start, end);
        } else if (start >= mid) {
            return query(root.right, start, end);
        }
        return Math.max(query(root.left,start,mid),query(root.right,mid,end));
    }

    public void add(SegmentNode root, int start, int end, int maxHeight){
        if(start<=root.start && end>=root.end){
            root.maxHeight = maxHeight;
            root.left = null;
            root.right = null;
            return;
        }
        if(start>=root.end || root.start>=end) return;
        if(root.left==null){
            int mid = root.start + (root.end - root.start) / 2;
            root.left = new SegmentNode(root.start,mid,0);
            root.right = new SegmentNode(mid,root.end,0);
        }
        add(root.left,start,end,maxHeight);
        add(root.right,start,end,maxHeight);
        root.maxHeight = Math.max(root.left.maxHeight,root.right.maxHeight);
    }
}
class SegmentNode{
    public SegmentNode left , right;
    public int start, end, maxHeight;
    public SegmentNode(int start, int end, int maxHeight){
        this.start = start;
        this.end = end;
        this.maxHeight = maxHeight;
    }
}

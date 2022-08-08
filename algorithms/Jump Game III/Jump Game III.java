class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] vis = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                int curr = q.poll();
                if(vis[curr])
                    continue;
                if(arr[curr] == 0)
                    return true;
                if(curr+arr[curr] < n)
                    q.add(curr+arr[curr]);
                if(curr-arr[curr] >= 0)
                    q.add(curr-arr[curr]);
                vis[curr] = true;
            }
        }
        return false;
    }
}

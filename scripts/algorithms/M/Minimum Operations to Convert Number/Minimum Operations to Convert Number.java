// Runtime: 907 ms (Top 10.13%) | Memory: 306.2 MB (Top 27.03%)
class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        int res = 0;
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> set = new HashSet<>();
        q.offer(start);

        while(!q.isEmpty()){
            int size = q.size();

            for(int i = 0;i<size;i++){
                int val = q.poll();
                if(val == goal)return res;
                if((val < 0 || val > 1000) || set.contains(val))continue;
                if(!set.contains(val))set.add(val);

                for(int num : nums){
                    q.offer(val + num);
                    q.offer(val - num);
                    q.offer(val ^ num);
                }
            }
            res++;
        }

        return -1;
    }
}

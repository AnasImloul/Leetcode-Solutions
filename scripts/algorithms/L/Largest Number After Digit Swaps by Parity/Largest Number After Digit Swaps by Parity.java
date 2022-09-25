// Runtime: 4 ms (Top 55.01%) | Memory: 41.3 MB (Top 44.82%)
class Solution {
    public int largestInteger(int num) {
        PriorityQueue<Integer> opq = new PriorityQueue<>();
        PriorityQueue<Integer> epq = new PriorityQueue<>();
        int bnum = num;
        while(num>0){
            int cur = num%10;
            if(cur%2==1){
                opq.add(cur);
            }else{
                epq.add(cur);
            }
            num /= 10;
        }
        StringBuilder sb = new StringBuilder();
        num = bnum;
        while(num>0){
            int cur = num%10;
            if(cur%2==1)
                sb.insert(0, opq.poll());
            else
                sb.insert(0, epq.poll());
            num /= 10;
        }
        return Integer.parseInt(sb.toString());
    }
}